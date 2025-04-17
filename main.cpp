#include<iostream>
#include<raylib.h>
#include "Game.hpp"

int main()
{
    Color grey = {29, 29, 27, 255};

    int windowWidth = 750;
    int windowHeight = 700;

    InitWindow(windowWidth, windowHeight, "Space Invaders");
    SetTargetFPS(60);

    Game game;

    while(WindowShouldClose() == false){

        game.HandleInput();

        game.Update();

        BeginDrawing();
        ClearBackground(grey);

        game.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}