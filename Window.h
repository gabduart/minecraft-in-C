#pragma once
#include "windows.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

class Window
{
    public:
        // constructor & destroyer
        Window();
        Window(const Window&) = delete;
        Window& operator = (const Window&) = delete;
        ~Window();

        bool ProcessMessages();
        HWND GetHandle() const { return m_hwnd; }

    private:
        HINSTANCE m_hinstance;
        HWND m_hwnd;
};