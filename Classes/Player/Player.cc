#include "Player.hh"

string Player::_getName() const
{
    return _name;
}

int Player::_getNumber() const
{
    return _number;
}

int Player::_getPace() const
{
    return _pace;
}

int Player::_getRate() const
{
    return _rate;
}

PlayerRole Player::_getRole() const
{
    return _role;
}

Move Player::pickMove(int action, int direction)
{
    if (action > 0)
        return playerAction(pickDirection(direction));
    else
        return playerDirection(pickDirection(direction));
}