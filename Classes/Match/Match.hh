#pragma once
#include <string>
#include <vector>
#include <map>
#include "../Team/Team.hh"

using namespace std;

static int matchId = 0;

class Match
{
private:
    vector<Team> _teams;
    int _time;
    bool _finish;
    map<string, int> _score;
    map<string, int> _shoots;

public:
    int _getTime();
    vector<Team> _getTeams();
    bool _getMatchStatus();

    void startMatch();
    void updateMatchScore(map<string, int> newScore);
    void updateMatchShoots(map<string, int> newShoots);

    Match(vector<Team> teams);
    ~Match();
};