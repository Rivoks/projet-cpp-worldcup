#pragma once
#include "../Player.hh"
#include "../ATK/PlayerATK.hh"

class PlayerGK : public Player
{

private:
    int _loon;

public:
    bool moveDir(Direction direction, PlayerATK playerAtk);
    int _getLoon() const;
    float operator-(PlayerATK const &playerAtk);
    PlayerGK(string name, int number, int pace, int loon);
    ~PlayerGK();
};
