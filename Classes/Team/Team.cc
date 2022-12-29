#include "Team.hh"

Team::Team(vector<PlayerATK> atk, vector<PlayerDEF> def, PlayerGK gk, string name) : _players{atk, def, gk}
{
    _teamId = idCpt;
    _name = name;
    idCpt++;

    _atkRate = (atk[0]._getRate() + atk[1]._getRate()) / 2;
    _defRate = (def[0]._getRate() + def[1]._getRate()) / 2;
    _genRate = (_atkRate + _defRate + gk._getRate()) / 3;
}

Team::~Team()
{
}

string Team::_getName() const
{
    return _name;
}

int Team::_getTeamId() const
{
    return _teamId;
}

int Team::_getAtkRate() const
{
    return _atkRate;
}

int Team::_getDefRate() const
{
    return _defRate;
}

int Team::_getGenRate() const
{
    return _genRate;
}