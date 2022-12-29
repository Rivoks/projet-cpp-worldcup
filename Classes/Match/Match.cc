#include "Match.hh"
#include <chrono>
#include <thread>

Match::Match(vector<Team> teams)
{
    _teams = teams;
    _time = 10;
    _finish = false;

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

void Match::updateMatchScore(map<string, int> newScore)
{
    _score = newScore;
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