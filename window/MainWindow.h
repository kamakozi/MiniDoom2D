//
// Created by ziga zoric on 02.05.25.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <SDL_render.h>
#include "Player/Player.h"


class MainWindow {
public:
    int run(int argc, char* argv[]);

private:
    Player player;

    static const int screenWidth= 650;
    static const int screenHeight = 480;
    static const int mapWidth = 10;
    static const int mapHeight = 10;

    int map[mapHeight][mapWidth] = {
            {1,1,1,1,1,1,1,1,1,1},
            {1,0,0,1,0,0,0,0,0,1},
            {1,0,0,1,0,0,0,0,0,1},
            {1,0,1,1,0,1,1,0,0,1},
            {1,0,0,0,0,1,1,0,0,1},
            {1,0,0,0,1,1,1,0,0,1},
            {1,0,0,0,1,1,1,0,0,1},
            {1,0,0,1,0,0,1,0,0,1},
            {1,0,0,0,0,0,1,0,0,1},
            {1,1,1,1,1,1,1,1,1,1}
    };

    bool handleInput(bool& running);
    void update();
    void render();

    SDL_Renderer* renderer = nullptr;
    SDL_Window* window = nullptr;


};



#endif //MAINWINDOW_H
