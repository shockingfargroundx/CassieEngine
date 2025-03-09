#ifndef ENGINE_H
#define ENGINE_H

#include "raylib.h"
#include "raymath.h"
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "rlImGui.h"
#include "rlImGuiColors.h"


class Engine {
public:
    Engine(int width, int height, const char* title);
    ~Engine();
    void Run();

private:
    bool isRunning;
    void Update();
    void Render();
};


#endif
