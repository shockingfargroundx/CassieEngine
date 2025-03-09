cmake_minimum_required(VERSION 3.10)
project(MyEngine)

set(CMAKE_CXX_STANDARD 17)
set(RAYLIB_DIR "C:/DEV/Raylib-Game-Engine/thirdparty/RAYLIB")
set(GLFW_DIR "C:/DEV/Raylib-Game-Engine/thirdparty/GLFW")
set(ImGui_DIR "C:/DEV/Raylib-Game-Engine/vendor/ImGui")
set(rlImGui_DIR "C:/DEV/Raylib-Game-Engine/vendor/rlImGui")

include_directories(${RAYLIB_DIR}/include)
link_directories(${RAYLIB_DIR}/lib)

include_directories(${ImGui_DIR})
include_directories(${ImGui_DIR}/backends)
include_directories(${rlImGui_DIR})
include_directories(${rlImGui_DIR}/extras)

include_directories(${GLFW_DIR}/include)
link_directories(${GLFW_DIR}/lib)




add_executable(MyEngine src/main.cpp src/Engine.cpp
${ImGui_DIR}/imgui.cpp
${ImGui_DIR}/imgui_draw.cpp
${ImGui_DIR}/imgui_internal.h
${ImGui_DIR}/imstb_textedit.h
${ImGui_DIR}/imstb_rectpack.h
${ImGui_DIR}/imstb_truetype.h
${ImGui_DIR}/imconfig.h
${ImGui_DIR}/imgui_tables.cpp
${ImGui_DIR}/imgui_widgets.cpp
${ImGui_DIR}/backends/imgui_impl_opengl3.cpp
${ImGui_DIR}/backends/imgui_impl_glfw.cpp

${rlImGui_DIR}/rlImGui.cpp
${rlImGui_DIR}/rlImGui.h
${rlImGui_DIR}/imgui_impl_raylib.h
${rlImGui_DIR}/rlImGuiColors.h

)


target_link_libraries(MyEngine raylib opengl32 gdi32 winmm glfw3)
