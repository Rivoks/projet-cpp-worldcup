#pragma once
#include <string>
#include "../Move/Move.hh"

using namespace std;

enum PlayerRole
{
    ATK,
    DEF,
    GK
};

class Player
{

protected:
    string _name;
    string _directionName;
    string _actionName;
    PlayerRole _role;
    int _number;
    int _rate;
    int _pace;

public:
    string _getName() const;
    int _getNumber() const;
    int _getPace() const;
    int _getRate() const;

    Move pickMove(int action = 0, int direction = RANDOM);

    virtual Move playerDirection(Direction direction) = 0;
    virtual Move playerAction(Direction direction) = 0;
};