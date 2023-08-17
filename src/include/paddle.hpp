#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <raylib.h>

#include "consts.hpp"
#include "ball.hpp"

class Paddle
{
    private:
        /* data */
    public:
        double speed;
        Vector2 pos;

        Paddle();
        ~Paddle();

        void Draw();
        void Update(Ball *ball);
        void OnBallCollision(Ball *ball);
};

Paddle::Paddle()
{
    pos.x = 10;
    pos.y = HEIGHT/2-45;
    speed = 0;
}

Paddle::~Paddle()
{
}

void Paddle::Draw()
{
    DrawRectangleRounded(
        Rectangle{pos.x, pos.y, PADDLE_WIDTH, PADDLE_HEIGHT},
        0.5, 10, WHITE
    );
}

void Paddle::Update(Ball *ball)
{
    OnBallCollision(ball);

    if (IsKeyDown(KEY_W))
        speed = -6;
    else if (IsKeyDown(KEY_S))
        speed = 6;
    else 
        speed = 0;

    if (pos.y+speed <= HEIGHT-PADDLE_HEIGHT && pos.y+speed >= 0)
        pos.y+=speed;
}

void Paddle::OnBallCollision(Ball *ball)
{
    bool has_collided = CheckCollisionCircleRec(
        ball->pos, ball->radius,
        Rectangle{pos.x, pos.y, PADDLE_WIDTH, PADDLE_HEIGHT}
    );
    
    if (has_collided)
        ball->velocity.x *= -1;
}

#endif