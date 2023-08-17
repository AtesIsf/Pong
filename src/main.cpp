#include <raylib.h>
#include "include/consts.hpp"
#include "include/game.hpp"

int main()
{
    InitWindow(WIDTH, HEIGHT, GAME_TITLE);
    SetTargetFPS(TARGET_FPS);

    Game *game = new Game();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        // Updating
        game->Update();

        // Drawing
        ClearBackground(BLACK);
        DrawLine(WIDTH/2, 0, WIDTH/2, HEIGHT, WHITE);

        game->Draw();
        
        DrawRectangleRounded(
            Rectangle{10, HEIGHT/2-45, 18, 90},
            0.5, 10, WHITE
        );
        DrawRectangleRounded(
            Rectangle{WIDTH-28, HEIGHT/2-45, 18, 90},
            0.5, 10, WHITE
        );


        EndDrawing();
    }
    
    delete game;

    CloseWindow();
    return 0;
}