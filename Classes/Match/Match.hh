#pragma once
#include <string>
#include <list>
#include "Team.hh"

using namespace std;

class Match
{

private:
    list<Team> teams;
    int time;
    bool finish;

public:
    int getTime();
    list<int> getTeamList();

    bool getMatchStatus();
    void updateMatchStatus();

    Match(list<Team> teams);
    ~Match();
};