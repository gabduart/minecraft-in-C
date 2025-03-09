#include "Renderer.h"

Renderer::Renderer(HWND hwnd) : m_hwnd(hwnd) {}

void Renderer::Render() 
{
    std::cout << "Rendering frame...\n";
    Sleep(16);
    // upgrades for directx or opengl
}

void Renderer::DrawRectangle(HWND hwnd)
{
    PAINTSTRUCT ps;
    HDC hdevice_context = BeginPaint(hwnd, &ps);

    RECT clientRect;
    GetClientRect(hwnd, &clientRect);

    int rectW = 400;
    int rectH = 200;

    // top right corner
    int left = clientRect.right - rectW;
    int top = 0;
    int right = clientRect.right;
    int bottom = rectH;

    RECT tempRect = { left, top, right, bottom };

    // drawing and paint rect
    HBRUSH brush = CreateSolidBrush(RGB(0, 255, 0));
    FillRect(hdevice_context, &tempRect, brush);

    DeleteObject(brush);
    EndPaint(hwnd, &ps);
}