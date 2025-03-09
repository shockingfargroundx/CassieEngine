#include "Engine.h"
#include "iostream"
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

        // Handle keyboard input (e.g., moving an object with arrow keys)
    if (IsKeyDown(KEY_D)) {
        // Move object right
    }
    if (IsKeyDown(KEY_A)) {
        // Move object left
    }
    if (IsKeyDown(KEY_W)) {
        // Move object up
    }
    if (IsKeyDown(KEY_S)) {
        // Move object down
    }

    // Handle mouse input (e.g., left-click to change color)
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        // Change something or trigger an event on mouse click
    }

    // Get mouse position
    Vector2 mousePosition = GetMousePosition();
    // Maybe use the mouse position to interact with objects or UI

}

void Engine::Render() {
    // Start drawing
    BeginDrawing();
    ClearBackground(RAYWHITE);

        rlImGuiBegin();  // Render Imgui context

        // Create a fullscreen dockspace
        //ImGui::DockSpaceOverViewport();
        ImGui::Begin("DockSpace");
        ImGui::DockSpace(ImGui::GetID("MainDockspace"));
           ImGui::End();

        ImGui::Begin("Cube Settings Test");
        ImGui::Text("Hello World from ImGUI");
        ImGui::End();

        ImGui::Begin("File Heiharchy");

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
        ImGui::Begin("Viewport Panel");
        ImGui::Text("Game Rendering GOes here");
        ImGui::End();

        ImGui::Begin("Inspector");
        ImGui::Text("Object Settings go here");
        ImGui::End();
        // Rendering 


        rlImGuiEnd();  // End ImGui frame

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        DrawRectangle(190, 200, 15, 15, RED);

    
    // End drawing
    EndDrawing();

}
void Viewport(){
            ImGui::Begin("Viewport");
        ImVec2 viewportSize = ImGui::GetContentRegionAvail(); // Get size of the viewport

        ImGui::End;
}