#include <iostream>
#include <vector>
#include <future>
#include "Classes/Player/ATK/PlayerATK.hh"
#include "Classes/Player/DEF/PlayerDEF.hh"
#include "Classes/Player/GK/PlayerGK.hh"
#include "Classes/Action/Action.hh"
#include "Classes/Team/Team.hh"
#include "Classes/Match/Match.hh"

Team _createTeam()
{
    PlayerATK ronaldo("Ronaldo", 7, 81, 92, 85);
    PlayerATK messi("Messi", 10, 91, 84, 88);
    PlayerDEF hakimi("Hakimi", 2, 95, 76, 78);
    PlayerDEF ramos("Ramos", 4, 88, 80, 72);
    PlayerGK bono("Bono", 13, 79, 86);

    vector<PlayerATK> atk{ronaldo, messi};
    vector<PlayerDEF> def{ramos, hakimi};

    Team team(atk, def, bono, "Blue Dragon");
    return team;
    // std::cout << team._getName() << std::endl;
    // std::cout << "GEN:" << team._getGenRate() << std::endl;
    // std::cout << "ATK:" << team._getAtkRate() << std::endl;
    // std::cout << "DEF:" << team._getDefRate() << std::endl;
    // std::cout << team._players.atk[0]._getName() << std::endl;
}

void _runMatch(Match *match)
{
    int playerIndex = 0;
    Team playerTeam = match->_getTeams()[0];
    Team botTeam = match->_getTeams()[1];

    while (!match->_getMatchStatus())
    {
        if (playerIndex % 5 < 2) // TODO: ATK -> 0 or 1
        {
            PlayerATK player = playerTeam._players.atk[playerIndex % 2];
            PlayerDEF bot = botTeam._players.def[playerIndex % 2];
            PlayerGK gk = botTeam._players.gk;

            Action action(ATK, DEF);
            if (action.startAction(player, bot, gk))
                std::cout << "Goooooaaaaaal!" << std::endl;
            else
                std::cout << "Oh no! You missed this action..." << std::endl;
        }
        else if (playerIndex % 5 < 4) // TODO: DEF -> 2 or 3
        {
            PlayerDEF player = playerTeam._players.def[playerIndex % 2];
            PlayerATK bot = botTeam._players.atk[playerIndex % 2];
            PlayerGK gk = botTeam._players.gk;

            Action action(ATK, DEF);
            if (action.startAction(bot, player, gk))
                std::cout << "You have stopped to offensive!" << std::endl;
            else
                std::cout << "Oh no! You missed this action..." << std::endl;
        }
        else
        {
            PlayerATK player = botTeam._players.atk[playerIndex % 2];
            PlayerDEF bot = botTeam._players.def[playerIndex % 2];
            PlayerGK gk = playerTeam._players.gk;

            Action action(ATK, DEF);
            if (action.startAction(player, bot, gk))
                std::cout << "You saved the ball!" << std::endl;
            else
                std::cout << "Oh no! You missed this action..." << std::endl;
        }
        playerIndex++; // TODO: playerIndex
        std::cout << "\n==============\n"
                  << std::endl;
    }
    std::cout << "Match is over!" << std::endl;
}

void _initMatch()
{

    Team team1 = _createTeam();
    Team team2 = _createTeam();
    vector<Team> teams{team1, team2};

    Match match(teams);

    auto f = std::async(&Match::startMatch, &match);

    _runMatch(&match);
}

int main()
{
    _initMatch();

    return 0;
}