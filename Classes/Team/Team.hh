#pragma once
#include <string>
#include <list>
#include "../Player/Player.hh"

using namespace std;

class Team
{
private:
    int teamId;
    list<Player> players;
    string name;
    string color;
    int genRate;
    int atkRate;
    int defRate;

public:
    int _getGenRate();
    int _getAtkRate();
    int _getDevRate();
    Team(list<Player> players, string name, string color);
    ~Team();
};