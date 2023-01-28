#pragma once
#include <string>
#include <vector>
#include "../Match/Match.hh"
#include "../Team/Team.hh"

using namespace std;
 
class Tournament
{
private:

    vector<Team> _teamsList;
    bool _tournamentStatus;
    int _myTeamNb;

public:


    vector<Team> _getTeams();
    bool _getTournamentStatus();
    // Team _getMyTeam();

    void _updateTournamentStatus();
    Tournament(vector<Team> teams, int teamChoice);
    ~Tournament();
};