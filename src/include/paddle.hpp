#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <raylib.h>

#include "consts.hpp"

class Paddle
{
    private:
        /* data */
    public:
        bool is_player;
        double speed;
        Vector2 pos;

        Paddle(bool is_player);
        ~Paddle();

        void Draw();
};

Paddle::Paddle(bool is_player)
{
    this->is_player = is_player;
    if (is_player)
        pos.x = 10;
    else
        pos.x = WIDTH-28;
    pos.y = HEIGHT/2-45;
}

Paddle::~Paddle()
{
}

void Paddle::Draw()
{
    DrawRectangleRounded(
        Rectangle{pos.x, pos.y, 18, 90},
        0.5, 10, WHITE
    );
}

#endif