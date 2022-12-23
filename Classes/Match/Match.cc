#include "Match.hh"

int Match::matchId = 0;

Match::Match(list<Team> teams)
{
    _teams = teams;
    _time = 120;
    _finish = false;
    _score = {{0, 0},
              {1, 0}};
    _shoots = {{0, 0},
               {1, 0}};
}

Match::~Match()
{
    delete &_teams;
    delete &_time;
    delete &_finish;
    delete &_score;
    delete &_shoots;
}

int Match::_getTime()
{
    return _time;
}

list<Team> Match::_getTeamList()
{
    return _teams;
}

bool Match::_getMatchStatus()
{
    return _finish;
}

void Match::updateMatchStatus()
{
    _finish = true;
}

void Match::updateMatchScore(map<int, int> newScore)
{
    _score = newScore;
}

void Match::updateMatchShoots(map<int, int> newShoots)
{
    _shoots = newShoots;
}