#ifndef GAME_H
#define GAME_H

#include <raylib.h>
#include <raymath.h>

#include "ball.hpp"
#include "paddle.hpp"
#include "comppaddle.hpp"
#include "consts.hpp"

class Game
{
    private:
        /* data */
    public:
        Ball *ball;
        Paddle *player;
        CompPaddle *comp;
        // x->player, y->computer
        Vector2 scores;
        bool is_over;

        Game();
        ~Game();

        void Draw();
        void Update();

        void Goal(u_int8_t scorer);
        void GameOver();
};

Game::Game()
{
    ball = new Ball(6, 6);
    player = new Paddle();
    comp = new CompPaddle();
    scores.x = 0;
    scores.y = 0;
    is_over = false;
}

Game::~Game()
{
    delete ball;
    delete player;
    delete comp;
}

void Game::Draw()
{
    player->Draw();
    comp->Draw();
    ball->Draw();
}

void Game::Update()
{
    if (is_over && IsKeyPressed(KEY_SPACE))
    {
        is_over = false;
        Vector2Add(ball->velocity, Vector2{8, 8});
        scores.x = 0;
        scores.y = 0;
    }
    if (is_over)
        return;
    
    player->Update(ball);
    comp->Update(ball);
    ball->Update();

    // No bytes will be wasted
    u_int8_t scorer = ball->IsGoal();
    if (scorer > (u_int8_t)0)
        Goal(scorer);
}

// 1->player, 2->ai
void Game::Goal(u_int8_t scorer)
{
    if (scorer == (u_int8_t)1)
        scores.x++;
    else
        scores.y++;
    
    if (scores.x == 10 || scores.y == 10)
        GameOver();

    delete ball;
    ball = new Ball(6, 6);

    delete player;
    player = new Paddle();

    delete comp;
    comp = new CompPaddle();
}

void Game::GameOver()
{
    is_over = true;
    delete ball;
    ball = new Ball(0, 0);

    delete player;
    player = new Paddle();

    delete comp;
    comp = new CompPaddle();
}

#endif