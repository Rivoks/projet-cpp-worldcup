#pragma once
#include <string>
#include <vector>
#include "../Player/ATK/PlayerATK.hh"
#include "../Player/DEF/PlayerDEF.hh"
#include "../Player/GK/PlayerGK.hh"

using namespace std;

static int idCpt = 1;

class Team
{
private:
    int _teamId;
    string _name;
    int _genRate;
    int _atkRate;
    int _defRate;

public:
    int _getTeamId() const;
    string _getName() const;
    int _getGenRate() const;
    int _getAtkRate() const;
    int _getDefRate() const;
    void _printPlayers() const;

    struct Players
    {
        vector<PlayerATK> atk;
        vector<PlayerDEF> def;
        PlayerGK gk;
    } _players;

    Team(vector<PlayerATK> atk, vector<PlayerDEF> def, PlayerGK gk, string name);
    ~Team();
};