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
    string _getName();
    int _getNumber();
    int _getPace();
    int _getRate();

    virtual Move moveDir(Direction direction) = 0;
};