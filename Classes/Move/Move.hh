#pragma once
#include <cstdlib>
#include <ctime>
#include <stddef.h>
#include <string>
#include <iostream>

using namespace std;

enum Direction // The direction of a move can take three values, if it is Random, it takes randomly one of the three values
{
    LEFT,
    CENTER,
    RIGHT,
    RANDOM,
};

Direction pickDirection(int pick); // Function to select the Direction (in the enum)

class Move
{
private:
    // The move is based on a direction and on an accuracy
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