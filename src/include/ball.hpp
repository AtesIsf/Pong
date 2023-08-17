#ifndef BALL_H
#define BALL_H

#include <raylib.h>
#include <raymath.h>

#include "consts.hpp"

class Ball
{
    private:
        /* data */
    public:
        Vector2 pos;
        Vector2 velocity;
        int radius;

        Ball(int v_x, int v_y);
        ~Ball();

        void Draw();
        void Update();

        u_int8_t IsGoal();
};

Ball::Ball(int v_x, int v_y)
{
    radius = 15;
    pos.x = WIDTH/2;
    pos.y = HEIGHT/2;
    velocity.x = v_x;
    velocity.y = v_y;
}

Ball::~Ball()
{
}

void Ball::Draw()
{
    DrawCircle(pos.x, pos.y, radius, WHITE);
}

void Ball::Update()
{
    pos.x+=velocity.x;
    pos.y+=velocity.y;

    // Up-Down border hit
    if (pos.y+radius >= HEIGHT || pos.y-radius <= 0) 
        velocity.y *= -1;
}

// 0->false, 1->player goal, 2->ai goal
uint8_t Ball::IsGoal()
{
    if (pos.x+radius >= WIDTH) 
        return 1;
    if (pos.x-radius <= 0)
        return 2;
    return 0;
}

#endif