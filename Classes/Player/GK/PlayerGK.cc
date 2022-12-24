#include "PlayerGK.hh"
#include <cmath>

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

bool PlayerGK::moveDir(Direction direction, PlayerATK playerAtk)
{
    std::srand(std::time(nullptr));
    int random = std::rand();

    Move moveAtk(float((playerAtk._getShoot()) / 100.0)); // Random direction for the ATK and accuracy based on his stats
    Move moveGK(direction, float((_rate) / 100.0));

    bool sameDir = moveGK._getDirection() == moveAtk._getDirection(); // Checking if the GK has choosen same direction as the ATK

    if (sameDir) // If yes, random chance to stop the shoot
        return float(random % 100) / 100.0 < 0.7 + (moveGK._getAccuracy() - moveAtk._getAccuracy());

    else if (std::abs(moveGK._getDirection() - moveAtk._getDirection()) == 1) // If the GK decision is not too far from the shoot it stills a chance to stop it
        return float(random % 100) / 100.0 < 0.7 + (moveGK._getAccuracy() - moveAtk._getAccuracy());

    return float(random % 100) / 100.0 < 0.15 + (moveGK._getAccuracy() - moveAtk._getAccuracy()); // A last chance to save the goal ...
};

float PlayerGK::operator-(PlayerATK const &playerATK) // Init the operator - to compare stats and get a coefficient
{
    return float((_rate - playerATK._getShoot())) / 100.0;
}
