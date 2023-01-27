#include "Match.hh"
#include <chrono>
#include <thread>


Match::Match(vector<Team> teams, int time)
{
    _teams = teams;
    _time = time;
    _finish = false;

    _matchId = matchId;
    matchId++;

    _score = {{teams[0]._getName(), 0},
              {teams[1]._getName(), 0}};
 
    _shoots = {{teams[0]._getName(), 0},
               {teams[1]._getName(), 0}};
}

Match::~Match()
{
}


int Match::_getTime()
{
    return _time;
}

vector<Team> Match::_getTeams()
{
    return _teams;
}

bool Match::_getMatchStatus()
{
    return _finish;
}

int Match::_getMatchId()
{
    return _matchId;
}

map<string, int> Match::_getScore() 
{
    return _score;
}

void Match::printScore() 
{
    for (const auto&[key, value] : _score) { 
        cout << key << " " << value << endl;
    }
}

void Match::updateMatchScore(int n)
{
    if (n>0) _score[_teams[0]._getName()] += 1;

    else _score[_teams[1]._getName()] += 1;
}

void Match::updateMatchShoots(map<string, int> newShoots)
{
    _shoots = newShoots;
}

void Match::startMatch()
{
    while (_time > 0)
    {
        _time -= 1;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
    _finish = true;
}