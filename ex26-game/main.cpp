#include <windows.h>

//g++ main.cpp -o main -lgdi32

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
int ballX = 100, ballY = 100, ballRadius = 25;  // Ball position and size
int triangleX = 400, triangleY = 0, triangleSpeed = 5; // Triangle position and speed
bool isGameOver = false;

// Function to process messages sent to the window
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_KEYDOWN:  // Check for key press
            if (!isGameOver) {
                switch (wp) {
                    case 'W': case 'w': ballY -= 10; break;  // Move up
                    case 'A': case 'a': ballX -= 10; break;  // Move left
                    case 'S': case 's': ballY += 10; break;  // Move down
                    case 'D': case 'd': ballX += 10; break;  // Move right
                }
            }
            InvalidateRect(hwnd, NULL, TRUE);  // Redraw window
            break;

        case WM_PAINT:
                    {
                        PAINTSTRUCT ps;
                        HDC hdc = BeginPaint(hwnd, &ps);

                        // Draw ball
                        HBRUSH ballBrush = CreateSolidBrush(RGB(0, 0, 255)); // Blue ball
                        SelectObject(hdc, ballBrush);
                        Ellipse(hdc, ballX - ballRadius, ballY - ballRadius, ballX + ballRadius, ballY + ballRadius);
                        DeleteObject(ballBrush);

                        // Draw triangle
                        HBRUSH triangleBrush = CreateSolidBrush(RGB(255, 0, 0)); // Red triangle
                        SelectObject(hdc, triangleBrush);
                        POINT triangle[3] = {
                            {triangleX, triangleY},
                            {triangleX - 30, triangleY + 60},
                            {triangleX + 30, triangleY + 60}};
                        Polygon(hdc, triangle, 3);
                        DeleteObject(triangleBrush);

                        // Draw Game Over text if collision
                        if (isGameOver)
                        {
                            TextOut(hdc, WINDOW_WIDTH / 2 - 50, WINDOW_HEIGHT / 2, "Game Over", 9);
                        }

                        EndPaint(hwnd, &ps);
                        break;
                    }

        case WM_TIMER:  // Timer event to move the triangle
            if (!isGameOver) {
                triangleY += triangleSpeed;  // Move triangle down

                // Reset triangle position if it moves out of window
                if (triangleY > WINDOW_HEIGHT) {
                    triangleY = 0;
                    triangleX = rand() % (WINDOW_WIDTH - 60) + 30; // Randomize x position
                }

                // Check collision
                int deltaX = ballX - triangleX;
                int deltaY = ballY - triangleY;
                int distanceSquared = deltaX * deltaX + deltaY * deltaY;
                int collisionDistance = ballRadius + 30;  // Approximate collision distance

                if (distanceSquared <= collisionDistance * collisionDistance) {
                    isGameOver = true;
                }

                InvalidateRect(hwnd, NULL, TRUE);  // Redraw window
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0); // Close the application
            break;
        default:
            return DefWindowProc(hwnd, msg, wp, lp);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const char* className = "GameWindowClass";
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProcedure;
    wc.hInstance = hInstance;
    wc.lpszClassName = className;
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);

    // Register window class
    RegisterClass(&wc);

    // Create window
    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles
        className,                      // Window class name
        "Moving Ball and Triangle Game", // Window title
        WS_OVERLAPPEDWINDOW,            // Window style
        CW_USEDEFAULT, CW_USEDEFAULT,   // Position
        WINDOW_WIDTH, WINDOW_HEIGHT,    // Width and height
        nullptr, nullptr, hInstance, nullptr
    );

    if (hwnd == nullptr) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // Set a timer for moving the triangle
    SetTimer(hwnd, 1, 30, NULL);

    // Main message loop
    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}