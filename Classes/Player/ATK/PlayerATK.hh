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

    virtual bool moveShoot(Direction direction);
    bool moveDribble(Direction direction, PlayerDEF playerDef);

    PlayerATK(string name, int number, int pace, int shoot, int skill);
    ~PlayerATK();
};
