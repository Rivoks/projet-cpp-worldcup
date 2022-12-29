#pragma once
#include "../Player.hh"
#include "../ATK/PlayerATK.hh"

class PlayerATK;

class PlayerGK : public Player
{

private:
    int _loon;

public:
    int _getLoon() const;

    Move playerDirection(Direction direction = RANDOM);
    Move playerAction(Direction direction = RANDOM);

    PlayerGK(string name, int number, int pace, int loon);
    ~PlayerGK();
};
