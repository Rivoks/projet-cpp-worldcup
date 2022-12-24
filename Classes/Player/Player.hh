#pragma once
#include <string>
#include "Move/Move.hh"

using namespace std;

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

    virtual Move moveDir(Direction direction) = 0;
};