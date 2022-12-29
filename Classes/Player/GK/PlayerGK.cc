#include "PlayerGK.hh"
#include <cmath>
#include <iostream>

PlayerGK::PlayerGK(string name, int number, int pace, int loon)
{
    _name = name;
    _number = number;
    _pace = pace;
    _loon = loon;
    _rate = (pace + loon) / 2;
};

PlayerGK::~PlayerGK(){};

int PlayerGK::_getLoon() const
{
    return _loon;
};

Move PlayerGK::playerDirection(Direction direction = RANDOM)
{

    float accuracy = (_loon * 0.4 + _pace * 0.6) / 100.0;

    if (direction == RANDOM)
    {
        Move newMove(accuracy);
        return newMove;
    }
    Move newMove(direction, accuracy);
    return newMove;
};

Move PlayerGK::playerAction(Direction direction = RANDOM)
{
    float accuracy = (_loon * 0.8 + _pace * 0.2) / 100.0;

    Move newMove(direction, accuracy);

    return newMove;
}

/**
 * @brief
 *
 *
bool PlayerGK::moveKeep(Direction direction, PlayerATK playerAtk)
{
    std::srand(std::time(nullptr));
    int random = std::rand();

    Move moveAtk(float((playerAtk._getShoot()) / 100.0)); // Random direction for the ATK and accuracy based on his stats
    Move moveGK(direction, float((_rate) / 100.0));

    std::cout << moveAtk._getDirection() << std::endl;

    bool sameDir = moveGK._getDirection() == moveAtk._getDirection(); // Checking if the GK has choosen same direction as the ATK

    if (sameDir) // If yes, random chance to stop the shoot
        return float(random % 100) / 100.0 < 0.7 + (moveGK._getAccuracy() - moveAtk._getAccuracy());

    else if (std::abs(moveGK._getDirection() - moveAtk._getDirection()) == 1) // If the GK decision is not too far from the shoot it stills a chance to stop it
        return float(random % 100) / 100.0 < 0.35 + (moveGK._getAccuracy() - moveAtk._getAccuracy());

    return float(random % 100) / 100.0 < 0.1 + (moveGK._getAccuracy() - moveAtk._getAccuracy()); // A last chance to save the goal ...
};
 *
 */
