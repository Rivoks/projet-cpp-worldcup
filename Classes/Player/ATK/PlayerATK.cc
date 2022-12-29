#include "PlayerATK.hh"

PlayerATK::PlayerATK(string name, int number, int pace, int shoot, int skill)
{
    _name = name;
    _number = number;
    _pace = pace;
    _role = ATK;
    _shoot = shoot;
    _skill = skill;
    _rate = (pace + shoot + skill) / 3;
};

PlayerATK::~PlayerATK(){};

int PlayerATK::_getShoot() const
{
    return _shoot;
};

int PlayerATK::_getSkill() const
{
    return _skill;
};

Move PlayerATK::playerDirection(Direction direction = RANDOM)
{

    float accuracy = (_skill * 0.7 + _pace * 0.3) / 100.0;
    if (direction == RANDOM)
    {
        Move newMove(accuracy);
        return newMove;
    }
    Move newMove(direction, accuracy);
    return newMove;
};

Move PlayerATK::playerAction(Direction direction = RANDOM)
{
    float accuracy = (_skill * 0.2 + _pace * 0.1 + _shoot * 0.7) / 100.0;
    Move newMove(direction, accuracy);

    return newMove;
}
