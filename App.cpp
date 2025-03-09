#include "App.h"

App::App() : m_renderer(m_window.GetHandle()) {}

void App::Run()
{
    while (m_window.ProcessMessages())
    {
        m_renderer.Render();
        Sleep(16); // ~60 FPS
    }
}