#include "Move.hh"

Move::Move(Direction direction, float accuracy)
{
    _direction = direction;
    _accuracy = accuracy;
}

Move::~Move()
{
}

Direction Move::_getDirection()
{
    return _direction;
}

float Move::_getAccuracy()
{
    return _accuracy;
}