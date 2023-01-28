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
    int _matchId; // Id of the match
    vector<Team> _teams; // The two teams of the match
    int _time; // Match duration
    bool _finish; // Is the match running ?
    map<string, int> _score; // Score of each team

public:
    // Getter
    int _getTime();
    vector<Team> _getTeams();
    bool _getMatchStatus();
    int _getMatchId();
    map<string, int> _getScore();

    bool _runMatch(); // Function that run the match
    void printScore(); // Print the score of the match
    void startMatch(); // Lead the match timer
    void updateMatchScore(int n);

    Match(vector<Team> teams, int time);
    ~Match();
};