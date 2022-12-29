#pragma once
#include <cstdlib>
#include <ctime>
#include <stddef.h>
#include <string>
#include <iostream>

using namespace std;

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
    string toString() const;

    void _setAccuracy(float newAccuracy);

    Move(float accuracy);
    Move(Direction direction, float accuracy);
    ~Move();

    bool operator-(Move const &moveIA);
};