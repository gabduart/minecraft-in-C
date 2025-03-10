#include "Window.h"
#include "Renderer.h"
#include <iostream>

Renderer* renderer = nullptr;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
        // ======= CREATION =======
        case WM_CREATE:
            renderer = new Renderer(hwnd); // initializes the renderer with the window
            break;

        // ======= CLOSE =======
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:
            if (renderer)
            {
                delete renderer;
                renderer = nullptr;
            }
            PostQuitMessage(0);
            return 0;

        // ======= PAINT =======
        case WM_PAINT:
            if (renderer)
            {
                renderer->DrawRectangle(hwnd); // calling the function to draw the rectangle
            }
            break;

        // ======= MOUSE =======
        case WM_LBUTTONDOWN:
            std::cout << "Left click detected!\n";
            break;

        case WM_RBUTTONDOWN:
            std::cout << "Right click detected!\n";
            break;

        // ======= KEYS =======
        case WM_KEYDOWN:
            if (wParam == VK_ESCAPE) 
            {
                DestroyWindow(hwnd); // Close the window with the ESC key
            }
            break;            
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

Window::Window() : m_hinstance(GetModuleHandle(nullptr))
{
    const wchar_t* CLASS_NAME = L"AppWindow";
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = m_hinstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(115, 199, 199)); // blue sky

    RegisterClass(&wc);
    m_hwnd = CreateWindowEx (
        0,
        CLASS_NAME,
        L"MineraCria",
        WS_OVERLAPPEDWINDOW, // type of window controls
        30, // top
        30, // left
        1297, // width
        670, // height
        nullptr,
        nullptr,
        m_hinstance,
        nullptr
    );

    ShowWindow(m_hwnd, SW_SHOW);
}

Window::~Window()
{
    const wchar_t* CLASS_NAME = L"AppWindow";
    UnregisterClass(CLASS_NAME, m_hinstance);
}

bool Window::ProcessMessages()
{
    MSG msg = {};
    while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
    {
        if (msg.message == WM_QUIT) return false;
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return true;
}