
#include "MainWindow.h"

#include <SDL.h>
#include <iostream>
#include "Player/Player.h"


int MainWindow::run(int argc, char* argv[]) {

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    window = SDL_CreateWindow("Hello SDL2", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }


    bool running = true;
    while (running) {
        handleInput(running);
        update();
        render();
        SDL_Delay(16);
    }


    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

void MainWindow::update() {
    std::cout <<"Player x: "<< player.x << "|| Player y: " << player.y << "|| Player angle: " << player.angle << std::endl;
}

void MainWindow::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
    SDL_RenderClear(renderer);


    float fov = M_PI / 3.0f;
    int numRays = screenWidth;

    for (int x = 0; x < numRays; x++) {
        float rayAngle = player.angle - (fov / 2.0f) + (x * fov / float(numRays));

        float distanceToWall = 0.0f;
        bool hitWall = false;

        float rayX = cos(rayAngle);
        float rayY = sin(rayAngle);

        float stepSize = 0.05f; // How fine to step forward
        float currentX = player.x;
        float currentY = player.y;


        while (!hitWall && distanceToWall < 20.0f) {
            currentX += rayX * stepSize;
            currentY += rayY * stepSize;
            distanceToWall += stepSize;

            int mapX = int(currentX);
            int mapY = int(currentY);

            if (mapX < 0 || mapX >= mapWidth || mapY < 0 || mapY >= mapHeight) {
                hitWall = true;
                distanceToWall = 20.0f;
            } else if (map[mapY][mapX] == 1) {
                hitWall = true;
            }
        }


        int lineHeight = int(screenHeight / distanceToWall);

        int drawStart = -lineHeight / 2 + screenHeight / 2;
        if (drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + screenHeight / 2;
        if (drawEnd >= screenHeight) drawEnd = screenHeight - 1;


        SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
        SDL_RenderDrawLine(renderer, x, drawStart, x, drawEnd);
    }

    SDL_RenderPresent(renderer);
}


bool MainWindow::handleInput(bool &running) {
    SDL_Event event;
    const Uint8 *keystate = SDL_GetKeyboardState(NULL);
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        }
    }
    float moveSpeed = 0.05f;
    float rotSpeed = 0.03f;

    if (keystate[SDL_SCANCODE_W]) {
        player.x += cos(player.angle) * moveSpeed;
        player.y += sin(player.angle) * moveSpeed;
    }
    if (keystate[SDL_SCANCODE_S]) {
        player.x -= cos(player.angle) * moveSpeed;
        player.y -= sin(player.angle) * moveSpeed;
    }

    if (keystate[SDL_SCANCODE_A]) {
        player.angle -= rotSpeed;
    }
    if (keystate[SDL_SCANCODE_D]) {
        player.angle += rotSpeed;
    }
}



