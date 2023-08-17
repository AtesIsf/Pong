#ifndef COMP_PADDLE_HPP
#define COMP_PADDLE_HPP

#include <raylib.h>

#include "paddle.hpp"
#include "consts.hpp"

class CompPaddle : public Paddle
{
    private:
        /* data */
    public:
        CompPaddle();

        void Update(Ball *ball);
};

CompPaddle::CompPaddle()
{
    pos.x = WIDTH-PADDLE_WIDTH-10;
    pos.y = HEIGHT/2-PADDLE_HEIGHT/2;
    speed = 0;
}

void CompPaddle::Update(Ball *ball)
{
    OnBallCollision(ball);

    if (ball->pos.y < pos.y+PADDLE_HEIGHT/2)
        speed = -6;
    if (ball->pos.y > pos.y+PADDLE_HEIGHT/2)
        speed = 6;

    if (pos.y+speed <= HEIGHT-PADDLE_HEIGHT && pos.y+speed >= 0)
        pos.y+=speed;
}

#endif