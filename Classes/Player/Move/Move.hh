#pragma once
#include <cstdlib>
#include <ctime>
#include <stddef.h>

enum Direction
{
    LEFT,
    CENTER,
    RIGHT,
};

class Move
{
private:
    Direction _direction;
    float _accuracy;

public:
    Direction _getDirection() const;
    float _getAccuracy() const;

    Direction pickDirection(int pick);

    Move(float accuracy);
    Move(Direction direction, float accuracy);
    ~Move();
};