#include <windows.h>

// Function to process messages sent to the window
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            
            // Set the color for the ball
            HBRUSH ballBrush = CreateSolidBrush(RGB(255, 0, 0)); // Red color
            SelectObject(hdc, ballBrush);

            // Draw a ball (circle) at specified coordinates and size
            int x = 100, y = 100, radius = 50;
            Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);

            // Clean up
            DeleteObject(ballBrush);
            EndPaint(hwnd, &ps);
            break;
        }
        case WM_DESTROY:
            PostQuitMessage(0); // Close the application
            break;
        default:
            return DefWindowProc(hwnd, msg, wp, lp);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const char* className = "SimpleWindowClass";
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
        "Window with Ball",             // Window title
        WS_OVERLAPPEDWINDOW,            // Window style
        CW_USEDEFAULT, CW_USEDEFAULT,   // Position
        800, 600,                       // Width and height
        nullptr, nullptr, hInstance, nullptr
    );

    if (hwnd == nullptr) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // Main message loop
    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}