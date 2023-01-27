#include "Showman.hh"

Showman::Showman(string name, int number, int pace, int shoot, int skill, string celebration)
{
    _name = name; // Name of the player
    _number = number; // Number of the player
    _celebration = celebration;
    //Stats of the player
    _pace = pace; // Pace of the player
    _role = ATK; // His role
    _shoot = shoot; // Stat of the shoot 
    _skill = skill; // Stat of the skill
    _rate = (pace + shoot + skill) / 3; // General rate
};

Showman::~Showman(){};

string Showman::_getCelebration() const
{
    return _celebration;
};

