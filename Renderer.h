#pragma once
#include <iostream>
#include <windows.h>

class Renderer
{
    public:
        Renderer(HWND hwnd);
        void Render();
    
    private:
        HWND m_hwnd;
};