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
        DrawText(TextFormat("%d", (int)(game->scores.x)), WIDTH/2-20, 0, 30, WHITE);
        DrawText(TextFormat("%d", (int)(game->scores.y)), WIDTH/2+4, 0, 30, WHITE);

        if (game->is_over)
            DrawText("Game Over!\nPress Space to\nRestart.", WIDTH/4, HEIGHT/4, 40, WHITE);

        game->Draw();

        EndDrawing();
    }
    
    delete game;

    CloseWindow();
    return 0;
}