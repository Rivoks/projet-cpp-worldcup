#include "Match.hh"
#include "../Action/Action.hh"
#include <chrono>
#include <thread>

bool _actionATK(Team playerTeam, Team botTeam, int playerIndex) // An action for an ATK
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

bool _actionDEF(Team playerTeam, Team botTeam, int playerIndex) // An action for a DEF
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

bool _actionGK(Team playerTeam, Team botTeam, int playerIndex) // An action for a GK
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

Match::Match(vector<Team> teams, int time)
{
    _teams = teams;
    _time = time;
    _finish = false;

    _matchId = matchId;
    matchId++;

    _score = {{teams[0]._getName(), 0},
              {teams[1]._getName(), 0}};
}

Match::~Match()
{
}

int Match::_getTime()
{
    return _time;
}

vector<Team> Match::_getTeams()
{
    return _teams;
}

bool Match::_getMatchStatus()
{
    return _finish;
}

int Match::_getMatchId()
{
    return _matchId;
}

map<string, int> Match::_getScore() 
{
    return _score;
}

void Match::printScore() 
{
    for (const auto&[key, value] : _score) { 
        cout << key << " " << value << endl;
    }
}

void Match::updateMatchScore(int n)
{
    if (n>0) _score[_teams[0]._getName()] += 1;

    else _score[_teams[1]._getName()] += 1;
}

void Match::startMatch()
{
    while (_time > 0)
    {
        _time -= 1;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
    _finish = true;
}

bool Match::_runMatch() // Function that run entirely the match, it leads all the action in the match
{
    int playerIndex = 0; // Player Index to play with all the players of the team
    Team playerTeam = _teams[0]; // Team 0 vs Team 1 
    Team botTeam = _teams[1];

    while (not(_finish)) // While time is ruinning...
    {
        if (playerIndex % 5 < 2) // If the player is one of the two first player, he is an ATK
        {
            if(_actionATK(playerTeam, botTeam, playerIndex)) Match::updateMatchScore(1); // If there is goal, there is a goal
        }
        else if (playerIndex % 5 < 4) // If our player is a DEF
        {
            _actionDEF(playerTeam, botTeam, playerIndex);
        }
        else if (not(_actionGK(playerTeam, botTeam, playerIndex))) Match::updateMatchScore(0); // If our GK does not stop the ball, there is a goal

        playerIndex++;
        std::cout << "\n==============\n"
                  << std::endl;
    }
    std::cout << "Fin du Match !!!!" << std::endl << "Score du match : " << std::endl;
    Match::printScore();

    if (_score[_teams[0]._getName()] > _score[_teams[1]._getName()]) 
    {
        cout << "Victoire de " << _teams[0]._getName() << endl;
        return true;
    } 

    else 
    {   
        if (_score[_teams[0]._getName()] < _score[_teams[1]._getName()])
        {
            cout << "Victoire de " << _teams[1]._getName() << endl;
            return false;
        }
        
        else 
        {
            cout << "Victoire de " << _teams[(playerIndex%2 == 0)]._getName() << " Car d'après Hugo Lloris les séances de TAB sont de la lotterie..." << endl; // Because Hugo Lloris said that penalties were loteries...
            return not((playerIndex%2 == 0));
        }
    }
}
