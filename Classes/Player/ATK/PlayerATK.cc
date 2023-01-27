#include "PlayerATK.hh"

PlayerATK::PlayerATK(string name, int number, int pace, int shoot, int skill)
{
    _name = name; // Name of the player
    _number = number; // Number of the player
    //Stats of the player
    _pace = pace; // Pace of the player
    _role = ATK; // His role
    _shoot = shoot; // Stat of the shoot 
    _skill = skill; // Stat of the skill
    _rate = (pace + shoot + skill) / 3; // General rate
};

PlayerATK::~PlayerATK(){};

// Getter

int PlayerATK::_getShoot() const
{
    return _shoot;
};

int PlayerATK::_getSkill() const
{
    return _skill;
};

// Init the direction of the move of the ATK
Move PlayerATK::playerDirection(Direction direction = RANDOM)
{

    float accuracy = (_skill * 0.7 + _pace * 0.3) / 100.0; // Accuracy of the move based on his stats
    if (direction == RANDOM) // If the move is not defined, a random move is activate
    {
        Move newMove(accuracy);
        return newMove;
    }
    Move newMove(direction, accuracy);
    return newMove;
};

// Init the move of the ATK
Move PlayerATK::playerAction(Direction direction = RANDOM)
{
    float accuracy = (_skill * 0.2 + _pace * 0.1 + _shoot * 0.7) / 100.0; // Accuracy of the move based on his stats

    if (direction == RANDOM)
    {
        Move newMove(accuracy);
        return newMove;
    }

    Move newMove(direction, accuracy);
    return newMove;
}
