#pragma once
#include "../Player.hh"
#include "../DEF/PlayerDEF.hh"

class PlayerDEF;

class PlayerATK : public Player
{

private:
    int _shoot;
    int _skill;

public:
    int _getShoot() const;
    int _getSkill() const;

    bool moveDir(Direction direction, PlayerDEF playerDef);
    bool moveShoot(Direction direction);

    PlayerATK(string name, int number, int pace, int shoot, int skill);
    ~PlayerATK();
};
