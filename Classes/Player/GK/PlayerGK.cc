#include "PlayerGK.hh"
#include <cmath>
#include <iostream>

PlayerGK::PlayerGK(string name, int number, int pace, int loon)
{
    _name = name;
    _role = GK;
    _number = number;
    _pace = pace;
    _loon = loon;
    _rate = (pace + loon) / 2;
};

PlayerGK::~PlayerGK(){};

int PlayerGK::_getLoon() const
{
    return _loon;
};

Move PlayerGK::playerDirection(Direction direction)
{

    float accuracy = (_loon * 0.4 + _pace * 0.6) / 100.0;

    if (direction == RANDOM)
    {
        Move newMove(accuracy);
        return newMove;
    }
    Move newMove(direction, accuracy);
    return newMove;
};

Move PlayerGK::playerAction(Direction direction)
{
    float accuracy = (_loon * 0.8 + _pace * 0.2) / 100.0;

    if (direction == RANDOM)
    {
        Move newMove(accuracy);
        return newMove;
    }
    Move newMove(direction, accuracy);
    return newMove;
}
