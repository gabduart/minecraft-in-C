#include "Window.h"
#include <iostream>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch(uMsg) 
    {
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_LBUTTONDOWN:
            //MessageBox(hwnd, L"Clique esquerdo detectado!", L"Evento Mouse", MB_OK);
            std::cout << "Clique esquerdo detectado!\n";
            break;
        case WM_RBUTTONDOWN:
            std::cout << "Clique direito detectado!\n";
            break;
        case WM_KEYDOWN:
            if (wParam == VK_ESCAPE) {
                DestroyWindow(hwnd); // Fecha a janela com a tecla ESC
            }
            break;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

Window::Window() 
: m_hinstance(GetModuleHandle(nullptr))
{
    const wchar_t* CLASS_NAME = L"Test Window Class";

    WNDCLASS wndClass = {};
    wndClass.lpszClassName = CLASS_NAME;
    wndClass.hInstance = m_hinstance;
    wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.lpfnWndProc = WindowProc;
    wndClass.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(115, 199, 199));

    RegisterClass(&wndClass);

    int width = 640;
    int height = 480;

    DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;

    RECT rect;
    rect.left = 250;
    rect.top = 250;
    rect.right = rect.left + width;
    rect.bottom = rect.top + height;

    AdjustWindowRect(&rect, style, false);

    m_hwnd = CreateWindowEx (
        0,
        CLASS_NAME,
        L"Test",
        style,
        rect.left,
        rect.top,
        rect.right - rect.left,
        rect.bottom - rect.top,
        NULL,
        NULL,
        m_hinstance,
        NULL
    );

    ShowWindow(m_hwnd, SW_SHOW);
}

Window::~Window() 
{
    const wchar_t* CLASS_NAME = L"Test Window Class";

    UnregisterClass(CLASS_NAME, m_hinstance);
}

bool Window::ProcessMessages() 
{
    MSG msg = {};

    while (PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE))
    {
        if(msg.message == WM_QUIT)
        {
            return false;
        }

        TranslateMessage(&msg);
        DispatchMessage(&msg);

    }
    
    return true;
}