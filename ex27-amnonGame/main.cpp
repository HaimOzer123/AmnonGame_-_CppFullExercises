#include <windows.h>
#include <string>
#include <cstdlib>
#include <ctime>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 400;
const int GROUND_Y = 300;
const int INITIAL_JUMP_VELOCITY = -30;
const int INITIAL_CACTUS_SPEED = 14;
const int GRAVITY = 1;
const int BONE_POINTS = 5;
const int STEAK_POINTS = 10;
const int ITEM_HEIGHT = 150;
const int MAX_JUMP_HEIGHT = 200;

bool isGameOver = false;
bool isJumping = false;
bool isGameStarted = false;
bool toggleImage = false;
int amnonY = GROUND_Y;
int jumpVelocity = 0;
int cactusX = WINDOW_WIDTH;
int cactusSpeed = INITIAL_CACTUS_SPEED;
int score = 0;
int bestScore = 0;
int frameCounter = 0;
int speedIncreaseCounter = 0;
int jumpCount = 0;  // Added for double jump tracking

HBITMAP hAmnon1, hAmnon2, hCactus, hBone, hSteak;

int boneX = -100, steakX = -100;
bool boneActive = false, steakActive = false;

// Function to load bitmap images with a check
HBITMAP LoadBMPImage(LPCSTR filePath) {
    HBITMAP hBmp = (HBITMAP)LoadImage(NULL, filePath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    if (!hBmp) {
        MessageBox(NULL, "Failed to load image!", "Error", MB_ICONERROR);
    }
    return hBmp;
}

// Function to reset game variables
void ResetGame() {
    isGameOver = false;
    isGameStarted = false;
    isJumping = false;
    score = 0;
    amnonY = GROUND_Y;
    cactusX = WINDOW_WIDTH;
    cactusSpeed = INITIAL_CACTUS_SPEED;
    frameCounter = 0;
    speedIncreaseCounter = 0;
    jumpCount = 0;
    boneX = -100;
    steakX = -100;
    boneActive = false;
    steakActive = false;
}

// Function to spawn items randomly
void SpawnItems() {
    if (!boneActive && rand() % 100 < 20) { // 20% chance for bone
        boneX = WINDOW_WIDTH;
        boneActive = true;
    }
    if (!steakActive && rand() % 100 < 5) { // 5% chance for steak
        steakX = WINDOW_WIDTH;
        steakActive = true;
    }
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_KEYDOWN:
            if (wp == VK_SPACE) {
                if (!isGameStarted) {
                    isGameStarted = true;
                } else if (isGameOver) {
                    ResetGame();
                } else if (jumpCount < 2 && !isGameOver) {  // Allow up to two jumps
                    isJumping = true;
                    jumpVelocity = INITIAL_JUMP_VELOCITY;
                    jumpCount++;  // Increment jump count
                }
            }
            break;

        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            HDC hdcMem = CreateCompatibleDC(hdc);

            if (!isGameStarted) {
                TextOut(hdc, WINDOW_WIDTH / 2 - 60, WINDOW_HEIGHT / 2, "Press SPACE to Start", 18);
            } else if (isGameOver) {
                std::string gameOverText = "Game Over";
                std::string restartText = "Press SPACE to Restart";
                std::string scoreText = "Score: " + std::to_string(score);
                std::string bestScoreText = "Best Score: " + std::to_string(bestScore);

                TextOut(hdc, WINDOW_WIDTH / 2 - 50, WINDOW_HEIGHT / 2 - 40, gameOverText.c_str(), gameOverText.length());
                TextOut(hdc, WINDOW_WIDTH / 2 - 60, WINDOW_HEIGHT / 2, scoreText.c_str(), scoreText.length());
                TextOut(hdc, WINDOW_WIDTH / 2 - 80, WINDOW_HEIGHT / 2 + 20, bestScoreText.c_str(), bestScoreText.length());
                TextOut(hdc, WINDOW_WIDTH / 2 - 60, WINDOW_HEIGHT / 2 + 60, restartText.c_str(), restartText.length());

                if (score > bestScore) {
                    bestScore = score;
                }
            } else {
                HBRUSH groundBrush = CreateSolidBrush(RGB(100, 100, 100));
                RECT groundRect = { 0, GROUND_Y + 50, WINDOW_WIDTH, WINDOW_HEIGHT };
                FillRect(hdc, &groundRect, groundBrush);
                DeleteObject(groundBrush);

                HBITMAP hAmnon = (frameCounter / 10) % 2 == 0 ? hAmnon1 : hAmnon2;
                SelectObject(hdcMem, hAmnon);
                BitBlt(hdc, 50, amnonY - 50, 100, 100, hdcMem, 0, 0, SRCCOPY);

                // Draw cactus at 70x70 size
                SelectObject(hdcMem, hCactus);
                BitBlt(hdc, cactusX, GROUND_Y - 20, 70, 70, hdcMem, 0, 0, SRCCOPY);

                if (boneActive) {
                    SelectObject(hdcMem, hBone);
                    BitBlt(hdc, boneX, ITEM_HEIGHT, 50, 50, hdcMem, 0, 0, SRCCOPY);
                }
                if (steakActive) {
                    SelectObject(hdcMem, hSteak);
                    BitBlt(hdc, steakX, ITEM_HEIGHT, 50, 50, hdcMem, 0, 0, SRCCOPY);
                }

                std::string scoreText = "Score: " + std::to_string(score);
                TextOut(hdc, 10, 10, scoreText.c_str(), scoreText.length());
            }

            DeleteDC(hdcMem);
            EndPaint(hwnd, &ps);
            break;
        }

        case WM_TIMER:
            if (isGameStarted && !isGameOver) {
                frameCounter++;
                speedIncreaseCounter++;

                if (frameCounter % 33 == 0) {
                    score++;
                }

                if (frameCounter % 10 == 0) {
                    toggleImage = !toggleImage;
                }

                if (speedIncreaseCounter >= 500) {
                    cactusSpeed += 2;
                    speedIncreaseCounter = 0;
                }

                cactusX -= cactusSpeed;
                if (cactusX < -70) {
                    cactusX = WINDOW_WIDTH;
                }

                if (boneActive) {
                    boneX -= cactusSpeed;
                    if (boneX < -50) boneActive = false;
                }
                if (steakActive) {
                    steakX -= cactusSpeed;
                    if (steakX < -50) steakActive = false;
                }

                // Adjust jump to respect maximum height
                if (isJumping) {
                    amnonY += jumpVelocity;
                    jumpVelocity += GRAVITY;

                    // Cap the jump height, but allow downward movement
                    if (amnonY <= GROUND_Y - MAX_JUMP_HEIGHT) {
                        amnonY = GROUND_Y - MAX_JUMP_HEIGHT;
                        if (jumpVelocity < 0) {
                            jumpVelocity = 0; // Stop upward movement only
                        }
                    }

                    // Check if Amnon lands back on the ground
                    if (amnonY >= GROUND_Y) {
                        amnonY = GROUND_Y;
                        isJumping = false;
                        jumpCount = 0;  // Reset jump count when Amnon hits the ground
                    }
                }

                RECT amnonRect = { 50, amnonY - 50, 150, amnonY + 50 };
                
                // Adjusted cactus collision rectangle to be smaller    
                RECT cactusRect = { cactusX, GROUND_Y - 40, cactusX + 40, GROUND_Y };
                
                RECT boneRect = { boneX, ITEM_HEIGHT, boneX + 50, ITEM_HEIGHT + 50 };
                RECT steakRect = { steakX, ITEM_HEIGHT, steakX + 50, ITEM_HEIGHT + 50 };
                RECT intersection;  

                if (IntersectRect(&intersection, &amnonRect, &cactusRect)) {
                    isGameOver = true;
                }
                if (boneActive && IntersectRect(&intersection, &amnonRect, &boneRect)) {
                    score += BONE_POINTS;
                    boneActive = false;
                }
                if (steakActive && IntersectRect(&intersection, &amnonRect, &steakRect)) {
                    score += STEAK_POINTS;
                    steakActive = false;
                }

                SpawnItems();
                InvalidateRect(hwnd, NULL, TRUE);
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, msg, wp, lp);
    }
    return DefWindowProc(hwnd, msg, wp, lp); // Ensures all unhandled messages are processed
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    srand(static_cast<unsigned>(time(0)));
    const char* className = "AmnonGameWindow";
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProcedure;
    wc.hInstance = hInstance;
    wc.lpszClassName = className;
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0, className, "Amnon Game", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH, WINDOW_HEIGHT,
        nullptr, nullptr, hInstance, nullptr
    );

    if (hwnd == nullptr) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    hAmnon1 = LoadBMPImage("assets/amnon_walk1.bmp");
    hAmnon2 = LoadBMPImage("assets/amnon_walk2.bmp");
    hCactus = LoadBMPImage("assets/cactu.bmp");
    hBone = LoadBMPImage("assets/bone.bmp");
    hSteak = LoadBMPImage("assets/steak.bmp");

    SetTimer(hwnd, 1, 30, NULL);

    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    DeleteObject(hAmnon1);
    DeleteObject(hAmnon2);
    DeleteObject(hCactus);
    DeleteObject(hBone);
    DeleteObject(hSteak);

    return 0;
}
