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

bool PlayerATK::moveDribble(Direction direction, PlayerDEF playerDef)
{
    std::srand(std::time(nullptr));
    int random = std::rand();

    return float(random % 100) / 100.0 < 0.5 + (playerDef - *this);
};

bool PlayerATK::moveShoot(Direction direction, PlayerGK playerGk)
{
    std::srand(std::time(nullptr));
    int random = std::rand();

    Move moveGK(float((playerGk._getLoon()) / 100.0)); // Random direction for the GK and accuracy based on his stats
    Move moveAtk(direction, float((_shoot) / 100.0));

    bool sameDir = moveGK._getDirection() == moveAtk._getDirection(); // Checking if the GK has choosen same direction as the ATK

    if (sameDir)                                                                                     // If yes, low chance to score a goal
        return float(random % 100) / 100.0 < 0.1 + (moveGK._getAccuracy() - moveAtk._getAccuracy()); // Around 10 % chance to score (more or less according to stats)

    else if (std::abs(moveGK._getDirection() - moveAtk._getDirection()) == 1) // If the GK decision is not too far from the shoot better chance to score, around 65 % depends on stats
        return float(random % 100) / 100.0 > 0.35 + (moveGK._getAccuracy() - moveAtk._getAccuracy());

    return float(random % 100) / 100.0 < 0.7 + (moveGK._getAccuracy() - moveAtk._getAccuracy()); // A big chance to score
}
