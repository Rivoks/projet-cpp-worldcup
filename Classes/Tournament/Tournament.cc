#include "Tournament.hh"

Tournament::Tournament(vector<Team> teams, int teamChoice)
{
    _teamsList = teams;
    _myTeamNb = teamChoice;
    _tournamentStatus = true;

}

Tournament::~Tournament()
{
}

vector<Team> Tournament::_getTeams()
{
    return _teamsList;
}

bool Tournament::_getTournamentStatus()
{
    return _tournamentStatus;
}

void Tournament::_updateTournamentStatus() {
    _tournamentStatus = false;
}

