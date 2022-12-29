#include "Move.hh"

Move::Move(Direction direction, float accuracy)
{
    _direction = direction;
    _accuracy = accuracy;
}

Move::Move(float accuracy)
{
    srand(time(NULL));
    int random = rand();

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

string Move::toString() const
{
    switch (_direction)
    {
    case LEFT:
        return "LEFT";

    case CENTER:
        return "CENTER";

    case RIGHT:
        return "RIGHT";

    default:
        return "RANDOM";
    };
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

    case 2:
        return RIGHT;

    default:
        return RANDOM;
    }
}