#include <ctime>
#include <cstdlib>
#include "Move.hh"

Move::Move(Direction direction, float accuracy)
{
    _direction = direction;
    _accuracy = accuracy;
}

Move::Move(float accuracy)
{
    // std::srand(std::time(nullptr));
    // int random = std::rand() % 3;
    int random = 2;
    _direction = pickDirection(random);
    _accuracy = accuracy;
}

Move::~Move()
{
}

Direction Move::_getDirection() const
{
    return _direction;
}

float Move::_getAccuracy() const
{
    return _accuracy;
}

Direction Move::pickDirection(int pick)
{
    switch (pick)
    {
    case 0:
        return LEFT;

    case 1:
        return RIGHT;

    default:
        return CENTER;
    }
}