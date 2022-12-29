#include <ctime>
#include <cstdlib>
#include "PlayerDEF.hh"

PlayerDEF::PlayerDEF(string name, int number, int pace, int def, int stamina)
{
    _name = name;
    _role = DEF;
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

Move PlayerDEF::playerDirection(Direction direction = RANDOM)
{

    float accuracy = (_stamina * 0.5 + _def * 0.3 + _pace * 0.2) / 100.0;
    if (direction == RANDOM)
    {
        Move newMove(accuracy);
        return newMove;
    }
    Move newMove(direction, accuracy);
    return newMove;
};

Move PlayerDEF::playerAction(Direction direction = RANDOM)
{
    float accuracy = (_def * 0.8 + _def * 0.2) / 100.0;
    Move newMove(direction, accuracy);

    return newMove;
}

float PlayerDEF::operator-(PlayerATK const &playerAtk)
{
    return float((_def - playerAtk._getSkill())) / 100.0;
}

/**
 * @brief
 *
 * bool PlayerDEF::moveTackle(Direction direction, PlayerATK playerAtk)
{
    std::srand(std::time(nullptr));
    int random = std::rand();

    Move moveAtk(float((playerAtk._getPace() + playerAtk._getSkill()) / 200.0));
    Move moveDef(direction, float((_stamina + _def) / 200.0));

    bool sameDir = moveDef._getDirection() == moveAtk._getDirection();

    if (sameDir)
        return float(random % 100) / 100.0 < 0.7 + (moveDef._getAccuracy() - moveAtk._getAccuracy());

    return float(random % 100) / 100.0 < 0.15 + (moveDef._getAccuracy() - moveAtk._getAccuracy());
};

bool PlayerDEF::moveHandle(PlayerATK playerAtk)
{
    std::srand(std::time(nullptr));
    int random = std::rand();

    return float(random % 100) / 100.0 < 0.5 + (*this - playerAtk);
};
 *
 */