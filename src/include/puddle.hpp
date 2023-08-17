#ifndef PUDDLE_HPP
#define PUDDLE_HPP

#include <raylib.h>

#include "consts.hpp"

class Puddle
{
    private:
        /* data */
    public:
        bool is_player;
        double speed;
        Vector2 pos;

        Puddle(bool is_player);
        ~Puddle();

        void Draw();
};

Puddle::Puddle(bool is_player)
{
    this->is_player = is_player;
    if (is_player)
        pos.x = 10;
    else
        pos.x = WIDTH-28;
    pos.y = HEIGHT/2-45;
}

Puddle::~Puddle()
{
}

void Puddle::Draw()
{
    DrawRectangleRounded(
        Rectangle{pos.x, pos.y, 18, 90},
        0.5, 10, WHITE
    );
}

#endif