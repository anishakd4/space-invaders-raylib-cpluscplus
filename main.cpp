#include<iostream>
#include<raylib.h>
#include "Game.hpp"
#include<string.h>


std::string FormatWithLeadingZeros(int number, int width){
    std::string numberText = std::to_string(number);
    int leadingZeros = width - numberText.length();
    return numberText = std::string(leadingZeros, '0') + numberText;
}

int main()
{
    Color grey = {29, 29, 27, 255};
    Color yellow = {243, 216, 63, 255};

    int offset = 50;
    int windowWidth = 750;
    int windowHeight = 700;

    InitWindow(windowWidth + offset, windowHeight + (2 * offset), "Space Invaders");
    InitAudioDevice();

    Font font = LoadFont("../Font/monogram.ttf");
    Texture2D spaceshipImage= LoadTexture("../Graphics/spaceship.png");

    SetTargetFPS(60);

    Game game;

    while(WindowShouldClose() == false){
        UpdateMusicStream(game.music);
        game.HandleInput();

        game.Update();

        BeginDrawing();
        ClearBackground(grey);

        DrawRectangleRoundedLines({10, 10, 780, 780}, 0.18f, 20, yellow);
        DrawLineEx({25, 730}, {775, 730}, 3, yellow);

        if(game.run){
            DrawTextEx(font, "LEVEL 01", {570, 740}, 34, 2, yellow);
        }else{
            DrawTextEx(font, "GAME OVER", {570, 740}, 34, 2, yellow);
        }

        for(int i=0; i<game.lives; i++){
            DrawTextureV(spaceshipImage, { (float)(50 + (i * 50)), 745}, WHITE);
        }

        DrawTextEx(font, "SCORE", {50, 15}, 34, 2, yellow);
        std::string scoreText = FormatWithLeadingZeros(game.score, 5);
        DrawTextEx(font, scoreText.c_str(), {50, 40}, 34, 2, yellow);


        DrawTextEx(font, "HIGH SCORE", {570, 15}, 34, 2, yellow);
        std::string highScoreText = FormatWithLeadingZeros(game.highScore, 5);
        DrawTextEx(font, highScoreText.c_str(), {655, 40}, 34, 2, yellow);

        game.Draw();

        EndDrawing();
    }

    CloseWindow();
    CloseAudioDevice();
    return 0;
}