#pragma once
#include <string>
#include <list>
#include <map>
#include "Team.hh"

using namespace std;

class Match
{

private:
    static int matchId;
    list<Team> _teams;
    int _time;
    bool _finish;
    map<int, int> _score;
    map<int, int> _shoots;

public:
    int _getTime();
    list<Team> _getTeamList();
    bool _getMatchStatus();

    void updateMatchStatus();
    void updateMatchScore(map<int, int> newScore);
    void updateMatchShoots(map<int, int> newShoots);

    Match(list<Team> teams);
    ~Match();
};