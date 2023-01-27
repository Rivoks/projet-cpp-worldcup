#pragma once
#include <string>
#include <vector>
#include <map>
#include "../Team/Team.hh"

using namespace std;

static int matchId = 1;
 
class Match
{
private:
    int _matchId;
    vector<Team> _teams;
    int _time;
    bool _finish;
    map<string, int> _score;
    map<string, int> _shoots;

public:
    int _getTime();
    vector<Team> _getTeams();
    bool _getMatchStatus();
    int _getMatchId();
    map<string, int> _getScore();
    
    void printScore();
    void startMatch();
    void updateMatchScore(int n);
    void updateMatchShoots(map<string, int> newShoots);

    Match(vector<Team> teams, int time);
    ~Match();
};