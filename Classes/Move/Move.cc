#include "Move.hh"

Move::Move(Direction direction, float accuracy)
{
    _direction = direction;
    _accuracy = accuracy;
}

Move::Move(float accuracy)
{
    std::srand(std::time(NULL));
    int random = std::rand();

    _direction = pickDirection(random % 3);
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

void Move::_setAccuracy(float newAccuracy)
{
    _accuracy = newAccuracy;
}

bool Move::operator-(Move const &moveIA)
{
    return _accuracy - moveIA._getAccuracy() > 0;
}

/** Global Function */
Direction pickDirection(int pick)
{
    switch (pick)
    {
    case 0:
        return LEFT;

    case 1:
        return CENTER;

    default:
        return RIGHT;
    }
}