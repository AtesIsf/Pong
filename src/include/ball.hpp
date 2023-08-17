#ifndef BALL_H
#define BALL_H

#include <raylib.h>
#include <raymath.h>

class Ball
{
    private:
        /* data */
    public:
        Vector2 pos;
        Vector2 velocity;
        int radius;

        Ball();
        ~Ball();

        void Draw();
        void Update();

        bool HasHitBorders();
};

Ball::Ball()
{
    radius = 15;
    pos.x = WIDTH/2;
    pos.y = HEIGHT/2;
    velocity.x = 5;
    velocity.y = 5;
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
}

bool Ball::HasHitBorders()
{
    
}

#endif