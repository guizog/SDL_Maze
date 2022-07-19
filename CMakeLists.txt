cmake_minimum_required(VERSION 3.22)
project(SDL_Maze)

set(CMAKE_CXX_STANDARD 14)

set(SDL2_INCLUDE_DIR C:/libs/SDL2/include)
set(SDL2_LIB_DIR C:/libs/SDL2/lib/x86)
set(SDL2_IMAGE_INCLUDE_DIR C:/libs/SDL2_image/include)
set(SDL2_IMAGE_LIB_DIR C:/libs/SDL2_image/lib/x86)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

include_directories(${SDL2_IMAGE_INCLUDE_DIR})
link_directories(${SDL2_IMAGE_LIB_DIR})

add_executable(SDL_Maze main.cpp Node.cpp Node.h Maze.cpp Maze.h Texture.cpp Texture.h)
target_link_libraries(${PROJECT_NAME} SDL2main SDL2 SDL2_image)