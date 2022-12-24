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

    bool moveDir(Direction direction, PlayerATK playerAtk);
    bool moveHandle(PlayerATK playerAtk);

    PlayerDEF(string name, int number, int pace, int def, int stamina);
    ~PlayerDEF();

    float operator-(PlayerATK const &playerAtk);
};
