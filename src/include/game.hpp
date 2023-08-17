#ifndef GAME_H
#define GAME_H

#include <raylib.h>
#include <raymath.h>

#include "ball.hpp"
#include "consts.hpp"

class Game
{
    private:
        /* data */
    public:
        Ball *ball;

        Game(/* args */);
        ~Game();
        void Draw();
        void Update();
};

Game::Game(/* args */)
{
    ball = new Ball();
}

Game::~Game()
{
    delete ball;
}

void Game::Draw()
{
    ball->Draw();
}

void Game::Update()
{
    ball->Update();
}

#endif