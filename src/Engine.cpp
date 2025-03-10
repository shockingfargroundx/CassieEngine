#include "Engine.h"
#include <iostream>
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>  // Include GLFW for OpenGL context management

Engine::Engine(int width, int height, const char* title) {
    InitWindow(width, height, title);
    SetTargetFPS(60);

    rlImGuiSetup(true);

    // Enable docking
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;  // Enable docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;  // Optional: Multi-window support

    isRunning = !WindowShouldClose();
    viewportTex = LoadRenderTexture(width, height);

}

Engine::~Engine() {
    // Clean up ImGui and Raylib resources
    CloseWindow(); // Close window and OpenGL context
}

void Engine::Run() {
    while (!WindowShouldClose()) {
        Update();
        Render();
    }
    rlImGuiShutdown();
}

void Engine::Update() {
    // Handle input (no camera controls right now depricated)

    // Get mouse position
    Vector2 mousePosition = GetMousePosition();
    // Maybe use the mouse position to interact with objects or UI

}

void Engine::Render() {



    // In theory this will render in tex mode
    BeginTextureMode(viewportTex);

    ClearBackground(GRAY);

    DrawText("Game Scene Goes Here", 50, 50, 20, RAYWHITE);

    EndTextureMode(); // End Tex mode


    rlImGuiBegin();  // Render Imgui context

    // Create a fullscreen dockspace
    ImGui::Begin("DockSpace");
    ImGui::DockSpace(ImGui::GetID("MainDockspace"));
    ImGui::End();

    //Test Cube Settings
    ImGui::Begin("Object Settings");
    ImGui::Text("Select a Prop");
    ImGui::End();

    //File Tree
    ImGui::Begin("File Heiharchy Test");

    if (ImGui::TreeNode("Assets")) {
        if (ImGui::TreeNode("Textures")) {
            ImGui::Text("texture1.png");
            ImGui::Text("texture2.png");
            ImGui::TreePop();
        }

        if (ImGui::TreeNode("Models")) {
            ImGui::Text("model1.obj");
            ImGui::Text("model2.obj");
            ImGui::TreePop();
        }

        ImGui::TreePop();
    }
    ImGui::End();

    // Viewport
    ImGui::Begin("Viewport");
    rlImGuiImageRenderTexture(&viewportTex);

    ImGui::End();

    //Inspector
    ImGui::Begin("Inspector");
    ImGui::Text("Object Settings go here");

    ImGui::End();



    // Rendering 

    rlImGuiEnd();  // End ImGui frame

    /*DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
    DrawRectangle(190, 200, 15, 15, RED);*/


    EndDrawing();
}

class BoxObject {


};