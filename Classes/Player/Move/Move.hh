#pragma once

enum Direction
{
    LEFT,
    RIGHT,
    CENTER
};

class Move
{
private:
    Direction _direction;
    float _accuracy;

public:
    Direction _getDirection();
    float _getAccuracy();

    Move(Direction direction, float accuracy);
    ~Move();
};