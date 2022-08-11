cmake_minimum_required(VERSION 3.15)
project(SDLCMakeStarter LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED COMPONENTS OpenGL)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${OpenGL_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
include_directories(include/)

file(GLOB RoadVisualizer_SRCS
    "include/*.h*",
    "src/*.cpp"
)

add_executable(
    RoadVisualizer 
    ${RoadVisualizer_SRCS}
)

target_link_libraries(
    RoadVisualizer PRIVATE 
    ${SDL2_LIBRARIES}
    ${SDL2_IMAGE_LIBRARIES}
    OpenGL::OpenGL
)

target_compile_features(RoadVisualizer PRIVATE cxx_std_17)
install(TARGETS RoadVisualizer)