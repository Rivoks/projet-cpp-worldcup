#pragma once
#include <string>
#include "../Move/Move.hh"

using namespace std;

enum PlayerRole // The player can have three roles
{
    ATK,
    DEF,
    GK
};

class Player
{

protected:
    string _name;
    PlayerRole _role;
    int _number;
    int _rate;
    int _pace;

public:
    string _getName() const;
    PlayerRole _getRole() const;
    int _getNumber() const;
    int _getPace() const;
    int _getRate() const;

    Move pickMove(int action = 0, int direction = RANDOM);

    virtual Move playerDirection(Direction direction) = 0; // Direction and Action are virtual, they depend on the role of the player
    virtual Move playerAction(Direction direction) = 0;
};