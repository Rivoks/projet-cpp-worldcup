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

int PlayerATK::operator+(PlayerATK const &player)
{
    return (_rate + player._rate) / 2;
}