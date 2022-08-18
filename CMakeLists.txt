cmake_minimum_required(VERSION 3.15)
project(Tankzoid LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED COMPONENTS OpenGL)
find_package(SDL2_image REQUIRED)

# Add ImGUI
add_library(
	imgui
	./libs/ImGui/imgui.cpp
	./libs/ImGui/imgui_draw.cpp
	./libs/ImGui/imgui_tables.cpp
	./libs/ImGui/imgui_widgets.cpp
	./libs/ImGui/imgui_demo.cpp
	./libs/ImGui/imgui_impl_sdl.cpp
	./libs/ImGui/imgui_impl_sdlrenderer.cpp
)

target_include_directories(imgui PUBLIC ${SDL2_INCLUDE_DIRS})
target_include_directories(imgui PUBLIC ./libs/ImGui/)


include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${OpenGL_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
include_directories(include/)

add_custom_target(game_assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/assets ${CMAKE_CURRENT_BINARY_DIR}/assets
)

file(GLOB Tankzoid_SRCS
    "include/*.h*"
	"include/Entities/*.h*"
	"src/*.cpp"
	"src/Entities/*.cpp"
)

add_executable(
    Tankzoid 
    ${Tankzoid_SRCS}
)

add_dependencies(Tankzoid game_assets)

target_link_libraries(
    Tankzoid PRIVATE 
    ${SDL2_LIBRARIES}
    ${SDL2_IMAGE_LIBRARIES}
    OpenGL::OpenGL
	imgui
)

target_compile_features(Tankzoid PRIVATE cxx_std_17)
install(TARGETS Tankzoid)