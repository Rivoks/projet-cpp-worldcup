#include "PlayerATK.hh"

PlayerATK::PlayerATK(string name, int number, int pace, int shoot, int skill)
{
    _name = name;
    _number = number;
    _pace = pace;
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

bool PlayerATK::moveDir(Direction direction, PlayerDEF playerDef)
{
    return false;
};

bool PlayerATK::moveShoot(Direction direction)
{

    return false;
};