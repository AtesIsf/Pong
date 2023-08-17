#ifndef GAME_H
#define GAME_H

#include <raylib.h>
#include <raymath.h>

#include "ball.hpp"
#include "puddle.hpp"
#include "consts.hpp"

class Game
{
    private:
        /* data */
    public:
        Ball *ball;
        Puddle *player;
        Puddle *comp;

        Game(/* args */);
        ~Game();

        void Draw();
        void Update();

        void Goal(u_int8_t scorer);
};

Game::Game(/* args */)
{
    ball = new Ball();
    player = new Puddle(true);
    comp = new Puddle(false);
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
    ball->Update();

    // No bytes will be wasted
    u_int8_t scorer = ball->IsGoal();
    if (scorer > (u_int8_t)0)
        Goal(scorer);
}

// 1->player, 2->ai
void Game::Goal(u_int8_t scorer)
{
    delete ball;
    ball = new Ball();
}

#endif