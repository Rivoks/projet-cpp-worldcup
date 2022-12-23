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

PlayerATK::~PlayerATK()
{
    delete &_name;
    delete &_number;
    delete &_rate;
    delete &_pace;
    delete &_shoot;
    delete &_skill;
};

int PlayerATK::_getShoot()
{
    return _shoot;
};

int PlayerATK::_getSkill()
{
    return _skill;
};

Move PlayerATK::moveDir(Direction direction)
{
    Move move(direction, 0.5);
    return move;
};

Move PlayerATK::moveShoot(Direction direction)
{
    Move move(direction, 0.75);
    return move;
};
