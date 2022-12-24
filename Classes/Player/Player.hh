#pragma once
#include <string>
#include "Move/Move.hh"

using namespace std;

// typedef struct MoveParams
// {
//     Direction direction;
//     PlayerATK playerAtk;
//     PlayerDEF playerDef;
// };

class Player
{

protected:
    string _name;
    int _number;
    int _rate;
    int _pace;

public:
    string _getName() const;
    int _getNumber() const;
    int _getPace() const;
    int _getRate() const;

    // virtual bool moveDir(Direction direction) = 0;
    // virtual bool moveDir(MoveParams moveParams) = 0;
    // virtual bool moveDir(Direction direction, PlayerATK atk = pessi, PlayerDEF def = h) = 0;
};