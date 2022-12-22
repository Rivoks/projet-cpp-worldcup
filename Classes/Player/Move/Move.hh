#pragma once
#include "Direction.hh"

class Move
{
private:
    Direction direction;
    float accuracy;

public:
    Direction _getDirection();
    float _getAccuracy();
    Move(Direction direction, float accuracy);
    ~Move();
};