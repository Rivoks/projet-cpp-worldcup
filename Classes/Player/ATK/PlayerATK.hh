#pragma once
#include "../Player.hh"
#include "../DEF/PlayerDEF.hh"
#include "../GK/PlayerGK.hh"

class PlayerDEF;
class PlayerGK;

class PlayerATK : public Player
{

private:
    int _shoot;
    int _skill;

public:
    int _getShoot() const;
    int _getSkill() const;

    Move playerDirection(Direction direction);
    Move playerAction(Direction direction);

    PlayerATK(string name, int number, int pace, int shoot, int skill);
    virtual ~PlayerATK();
};
