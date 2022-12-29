#pragma once
#include <cstdlib>
#include <ctime>
#include <stddef.h>

enum Direction
{
    LEFT,
    CENTER,
    RIGHT,
    RANDOM,
};

Direction pickDirection(int pick);

class Move
{
private:
    Direction _direction;
    float _accuracy;

public:
    Direction _getDirection() const;
    float _getAccuracy() const;

    Move(float accuracy);
    Move(Direction direction, float accuracy);
    ~Move();

    bool operator-(Move const &moveIA);
};