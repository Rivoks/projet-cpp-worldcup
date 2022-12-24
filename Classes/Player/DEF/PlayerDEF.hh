#pragma once
#include "../Player.hh"
#include "../ATK/PlayerATK.hh"

class PlayerDEF : public Player
{

private:
    int _def;
    int _stamina;

public:
    int _getDef();
    int _getStamina();

    Move moveDir(Direction direction);
    bool moveHandle(PlayerATK playerAtk);

    PlayerDEF(string name, int number, int pace, int def, int stamina);
    ~PlayerDEF();

    float operator-(PlayerATK const &playerAtk);
};