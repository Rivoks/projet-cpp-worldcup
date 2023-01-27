#include <iostream>
#include <vector>
#include <future>
#include "Classes/Player/ATK/PlayerATK.hh"
#include "Classes/Player/DEF/PlayerDEF.hh"
#include "Classes/Player/GK/PlayerGK.hh"
#include "Classes/Action/Action.hh"
#include "Classes/Team/Team.hh"
#include "Classes/Match/Match.hh"

// Team _createTeam(int n)
// {
//     PlayerATK ronaldo("Ronaldo", 7, 81, 92, 85);
//     PlayerATK messi("Messi", 10, 91, 84, 88);
//     PlayerDEF hakimi("Hakimi", 2, 95, 76, 78);
//     PlayerDEF ramos("Ramos", 4, 88, 80, 72);
//     PlayerGK bono("Bono", 13, 79, 86);

//     vector<PlayerATK> atk{ronaldo, messi};
//     vector<PlayerDEF> def{ramos, hakimi};

//     Team team(atk, def, bono, "Blue Dragon");
//     Team team1(atk, def, bono, "Red Dragon");

//     if (n>0) return team;

//     else return team1;
//     // std::cout << team._getName() << std::endl;
//     // std::cout << "GEN:" << team._getGenRate() << std::endl;
//     // std::cout << "ATK:" << team._getAtkRate() << std::endl;
//     // std::cout << "DEF:" << team._getDefRate() << std::endl;
//     // std::cout << team._players.atk[0]._getName() << std::endl;
// }

Team _chooseTeam(int n) 
{
    if (n == 0) {
        PlayerATK ronaldo("Ronaldo", 7, 81, 92, 85);
        PlayerATK bruno("Bruno Fernandes", 8, 72, 86, 81);
        PlayerDEF ruben("Ruben Dias", 3, 73, 88, 88);
        PlayerDEF cancelo("Cancelo", 20, 85, 81, 73);
        PlayerGK patricio("Rui Patricio", 1, 79, 86);

        vector<PlayerATK> atk{ronaldo, bruno};
        vector<PlayerDEF> def{ruben, cancelo};

        Team team(atk, def, patricio, "Portugal");

        return team;
    }

    if (n == 1) {
        PlayerATK neymar("Neymar", 10, 87, 83, 93);
        PlayerATK vinicius("Vinicius", 20, 95, 79, 90);
        PlayerDEF thiago("Thiago Silva", 3, 79, 87, 76);
        PlayerDEF marquinhos("Marquinhos", 5, 79, 89, 80);
        PlayerGK alisson("Alisson", 1, 80, 86);

        vector<PlayerATK> atk{neymar, vinicius};
        vector<PlayerDEF> def{thiago, marquinhos};

        Team team(atk, def, alisson, "Brésil");

        return team;
    }
    
    else {
        PlayerATK neymar("Neymar", 10, 87, 83, 93);
        PlayerATK vinicius("Vinicius", 20, 95, 79, 90);
        PlayerDEF thiago("Thiago Silva", 3, 79, 87, 76);
        PlayerDEF marquinhos("Marquinhos", 5, 79, 89, 80);
        PlayerGK alisson("Alisson", 1, 80, 86);

        vector<PlayerATK> atk{neymar, vinicius};
        vector<PlayerDEF> def{thiago, marquinhos};

        Team team(atk, def, alisson, "Selecao");

        return team;
    }
        
}

bool _actionATK(Team playerTeam, Team botTeam, int playerIndex) 
{
    PlayerATK player = playerTeam._players.atk[playerIndex % 2]; // Our player will be an ATK against, firstly a DEF and then against a GK
    PlayerDEF bot = botTeam._players.def[playerIndex % 2]; // There is also two DEF
    PlayerGK gk = botTeam._players.gk; // Only one GK

    Action action(ATK, DEF); // The ATK is against a DEF so we init the Action ATK vs DEF
    if (action.startAction(player, bot, gk)) // We start the action, if the ATK beat the DEf, he can shoot
    {
        std::cout << "Goooooaaaaaal!" << std::endl; //  If the ATK beat the GK, there is a goal
        return true;
    }
    else
        std::cout << "L'occasion totalement gâchée..." << std::endl; // He missed his chance
        return false;
}

bool _actionDEF(Team playerTeam, Team botTeam, int playerIndex) 
{
    PlayerDEF player = playerTeam._players.def[playerIndex % 2]; 
    PlayerATK bot = botTeam._players.atk[playerIndex % 2]; // He will face an ATK 
    PlayerGK gk = botTeam._players.gk;

    Action action(DEF, ATK);
    if (action.startAction(bot, player, gk)) {
        std::cout << "Bien joué !!! L'attaque est complètement annhilée" << std::endl;
        return true;
    }
    else {
        std::cout << "Oulala le défenseur qui se fait complètement effacer..." << std::endl;
        return false;
    }
}

bool _actionGK(Team playerTeam, Team botTeam, int playerIndex) 
{
    PlayerATK player = botTeam._players.atk[playerIndex % 2];
    PlayerDEF bot = botTeam._players.def[playerIndex % 2];
    PlayerGK gk = playerTeam._players.gk;

    Action action(GK, ATK);
    if (action.startAction(player, bot, gk)) {
        std::cout << "Mais quel arrêt !!!!" << std::endl;
        return true;
    }
    else {
        std::cout << "Euh... le gardien qui est complètement à côté de la plaque sur ce coup" << std::endl;
        return false;
    }
}

void _runMatch(Match *match) // Function that run entirely the match, it leads all the action in the match
{
    int playerIndex = 0; // Player Index to play with all the players of the team
    Team playerTeam = match->_getTeams()[0]; // Team 0 vs Team 1 
    Team botTeam = match->_getTeams()[1];

    while (!match->_getMatchStatus()) // While time is ruinning...
    {
        if (playerIndex % 5 < 2) // If the player is one of the two first player, he is an ATK
        {
            if(_actionATK(playerTeam, botTeam, playerIndex)) match->updateMatchScore(1); // If there is goal, there is a goal
        }
        else if (playerIndex % 5 < 4) // If our player is a DEF
        {
            _actionDEF(playerTeam, botTeam, playerIndex);
        }
        else if (not(_actionGK(playerTeam, botTeam, playerIndex))) match->updateMatchScore(0); // If our GK does not stop the ball, there is a goal

        playerIndex++;
        std::cout << "\n==============\n"
                  << std::endl;
    }
    std::cout << "Fin du Match !!!!" << std::endl << "Score du match : " << std::endl;
    match->printScore();

    if (match->_getScore()[match->_getTeams()[0]._getName()] > match->_getScore()[match->_getTeams()[1]._getName()]) cout << "Victoire de " << match->_getTeams()[0]._getName() << endl;

    else cout << "Victoire de " << match->_getTeams()[1]._getName() << endl;
}

void _initMatch()
{
    int teamChoice;
    cout << "Select your team : \n (0) Portugal \n (1) Brésil" << endl;
    cin >> teamChoice;
    Team team1 = _chooseTeam(teamChoice);
    Team team2 = _chooseTeam(teamChoice + 1);
    vector<Team> teams{team1, team2};

    Match match(teams, 10);

    auto f = std::async(&Match::startMatch, &match);

    _runMatch(&match);
}

int main()
{
    _initMatch();

    return 0;
}