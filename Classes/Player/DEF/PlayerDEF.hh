#pragma once
#include "../Player.hh"
#include "../ATK/PlayerATK.hh"

class PlayerATK;

class PlayerDEF : public Player
{

private:
    int _def;
    int _stamina;

public:
    int _getDef();
    int _getStamina();

    Move playerDirection(Direction direction);
    Move playerAction(Direction direction);

    PlayerDEF(string name, int number, int pace, int def, int stamina);
    ~PlayerDEF();

    float operator-(PlayerATK const &playerAtk);
};
