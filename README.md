# Mini-Doom (Raycasting Engine in C++ with SDL2)

A simple raycasting engine inspired by classic 2.5D shooters like **Wolfenstein 3D** and early **DOOM**, built in **C++** using **SDL2**.

##  What This Project Does (So Far)

- Creates a window using SDL2
- Implements a basic game loop: `handleInput()`, `update()`, `render()`
- Supports player movement:
  - `W` / `S`: move forward/backward
  - `A` / `D`: rotate left/right
- Casts rays from the player to detect walls on a 2D map
- Renders vertical wall slices to create a fake 3D perspective

##  Tech Used

- **C++17**
- **SDL2** 
- Basic **trigonometry** 
- Custom 2D map array

##  Next Goals (Coming Soon)

- Add a 2D top-down minimap for debugging and learning
- Add simple texture rendering or color shading for depth
- Add enemy and item sprites
- Add collision detection (walls block the player)
- Organize rendering into a dedicated renderer class

##  How to Build

1. Make sure you have SDL2 installed:
   ```bash
   brew install sdl2
