#include "PlayerDEF.hh"

PlayerDEF::PlayerDEF(string name, int number, int pace, int def, int stamina)
{
    _name = name;
    _number = number;
    _pace = pace;
    _def = def;
    _stamina = stamina;
    _rate = (pace + def + stamina) / 3;
};

PlayerDEF::~PlayerDEF(){};

int PlayerDEF::_getDef()
{
    return _def;
};

int PlayerDEF::_getStamina()
{
    return _stamina;
};

Move PlayerDEF::moveDir(Direction direction)
{
    Move move(direction, _stamina / 100);
    return move;
};

bool PlayerDEF::moveHandle(PlayerATK playerAtk)
{
    // return this - playerAtk;
    return false;
};

float PlayerDEF::operator-(PlayerATK const &playerAtk)
{
    return float((_def - playerAtk._getSkill())) / 100.0;
}