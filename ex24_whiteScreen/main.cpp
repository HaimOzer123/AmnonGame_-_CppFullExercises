#include <windows.h>

//g++ main.cpp -o main -lgdi32

// Window Procedure function to handle events
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);  // Signal to close the application
            return 0;
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            // Set the background color to white
            HBRUSH whiteBrush = (HBRUSH)GetStockObject(WHITE_BRUSH);
            FillRect(hdc, &ps.rcPaint, whiteBrush);
            EndPaint(hwnd, &ps);
            return 0;
        }
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Define the window class
    const char CLASS_NAME[] = "WhiteWindowClass";
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);  // Set default background to white

    // Register the window class
    RegisterClass(&wc);

    // Create the window
    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles
        CLASS_NAME,                     // Window class
        "White Background Window",      // Window title
        WS_OVERLAPPEDWINDOW,            // Window style
        CW_USEDEFAULT, CW_USEDEFAULT, 500, 300, // Position and size
        NULL,                           // Parent window    
        NULL,                           // Menu
        hInstance,                      // Instance handle
        NULL                            // Additional application data
    );

    if (hwnd == NULL) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // Main message loop
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
