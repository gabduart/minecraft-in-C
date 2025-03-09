#pragma once
#include "Window.h"
#include "Renderer.h"

class App
{
    public:
        App();
        void Run();
    
    private:
        Window m_window;
        Renderer m_renderer;
};