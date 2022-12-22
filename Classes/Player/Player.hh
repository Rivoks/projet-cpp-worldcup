#pragma once
#include <string>
#include "Move.hh"
#include "Team.hh"

using namespace std;

class Player
{

private:
    Team team;
    string name;
    int number;
    int rate;
    int pace;

public:
    int _getPace();
    int _getRate();
    virtual Move moveDir();
};