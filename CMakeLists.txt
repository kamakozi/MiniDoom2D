cmake_minimum_required(VERSION 3.16)
project(sdlminigame)

set(CMAKE_CXX_STANDARD 17)

# Tell CMake where to find SDL2
list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew/opt/sdl2")

# Find the SDL2 package installed via Homebrew
find_package(SDL2 REQUIRED CONFIG)

# Create your game executable
add_executable(sdlminigame main.cpp
        window/MainWindow.cpp
        window/MainWindow.h
        window/Player/Player.cpp
        window/Player/player.h)

# Link against SDL2 (shared lib)
target_link_libraries(sdlminigame PRIVATE SDL2::SDL2)

# SDL2main is not needed on macOS but can be included if you want
if(TARGET SDL2::SDL2main)
    target_link_libraries(sdlminigame PRIVATE SDL2::SDL2main)
endif()
