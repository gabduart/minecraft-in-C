#pragma once
#include <iostream>
#include <windows.h>

class Renderer
{
    public:
        Renderer(HWND hwnd);
        void Render();
        void DrawRectangle(HWND hwnd);
    
    private:
        HWND m_hwnd;
};