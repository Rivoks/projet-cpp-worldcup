#include "Action.hh"
#include <iostream>
#include <vector>
#include <string>

Action::Action(PlayerRole playerRole, PlayerRole botRole) : _playerMove(0), _botMove(0)
{
    _playerRole = playerRole;
    _botRole = botRole;
}

Action::~Action()
{
}

vector<string> Action::getActionNames()
{
    vector<string> vect;

    switch (_playerRole)
    {
    case ATK:
        vect.push_back("Dribble");
        vect.push_back("Shoot");
        return vect;

    case DEF:
        vect.push_back("Handle");
        vect.push_back("Tackle");
        return vect;

    default:
        vect.push_back("Dive");
        vect.push_back("Jump");
        return vect;
    }
}

vector<int> Action::chooseAction(int move)
{
    int pickMove = move;
    int pickDir;

    vector<string> actionNames = getActionNames();

    if (pickMove < 0)
    {
        std::cout << "Choose an action: \n"
                  << "0 - " << actionNames[0] << "\n"
                  << "1 - " << actionNames[1] << "\n"
                  << std::endl;
        std::cin >> pickMove;
    }

    else if (pickMove > 1)
    {
        std::cerr << "Error: choosed action does not exist" << std::endl;
        exit(0);
    }

    std::cout << "Choose a direction to " << actionNames[pickMove] << "\n"
              << "0 - Left\n"
              << "1 - Center\n"
              << "2 - Right\n"
              << std::endl;

    std::cin >> pickDir;

    vector<int> pickResults;
    pickResults.push_back(pickMove);
    pickResults.push_back(pickDir);

    return pickResults;
}

bool Action::startAction(PlayerATK playerAtk, PlayerDEF playerDef, PlayerGK playerGk)
{
    return handleAction(playerAtk, playerDef, playerGk);
}

bool Action::handleAction(PlayerATK playerAtk, PlayerDEF playerDef, PlayerGK playerGk)
{
    vector<int> choices;

    if (_playerRole == GK || (_playerRole == ATK && _botRole == GK)) // You are GK || You are ATK vs GK
    {
        choices = chooseAction(1);
        return handleActionAtkGk(playerAtk, playerGk, choices);
    }

    else if (_playerRole == ATK && _botRole == DEF) // You are ATK vs DEF
    {
        choices = chooseAction();
        if (handleActionAtkDef(playerAtk, playerDef, choices)) // You passed the DEF, you are ATK vs GK
        {
            std::cout << "You have passed the defense!\n-"
                      << std::endl;
            choices = chooseAction(1);
            _botRole = GK;
            return handleActionAtkGk(playerAtk, playerGk, choices);
        }
        std::cout << "Defense stopped you!" << std::endl;
        return false;
    }

    else if (_playerRole == DEF && _botRole == ATK) // You are DEF vs ATK
    {
        bool res = handleActionAtkDef(playerAtk, playerDef, choices);
        if (res)
            std::cout << "You have blocked the offensive!" << std::endl;
        return res;
    }

    std::cerr << "Error: DEF and GK cannot handle together" << std::endl;
    return false;
}

bool Action::handleActionAtkDef(PlayerATK playerAtk, PlayerDEF playerDef, vector<int> choices)
{

    float adjustment;

    if (_playerRole == ATK)
    {
        std::cout << playerAtk._getName() << " vs " << playerDef._getName() << std::endl;
        _playerMove = playerAtk.pickMove(choices[0], choices[1]);
        _botMove = playerDef.pickMove();
        adjustment = _playerMove._getDirection() == _botMove._getDirection() ? -0.07 : 0.05;
    }
    else if (_playerRole == DEF)
    {
        std::cout << playerDef._getName() << " vs " << playerAtk._getName() << std::endl;
        _playerMove = playerDef.pickMove(choices[0], choices[1]);
        _botMove = playerAtk.pickMove();
        adjustment = _playerMove._getDirection() == _botMove._getDirection() ? 0.05 : -0.07;
    }
    else
    {
        std::cerr << "Wrong handle action used (one of two players is not ATK/DEF" << std::endl;
        exit(0);
    }

    _playerMove._setAccuracy(_playerMove._getAccuracy() + adjustment);

    std::cout << _playerMove._getAccuracy()
              << " ( - ) "
              << _botMove._getAccuracy()
              << " • bot: "
              << _botMove.toString()
              << std::endl;

    return _playerMove - _botMove;
}

bool Action::handleActionAtkGk(PlayerATK playerAtk, PlayerGK playerGk, vector<int> choices)
{
    if (_playerRole == ATK)
    {
        std::cout << playerAtk._getName() << " vs " << playerGk._getName() << std::endl;
        _playerMove = playerAtk.pickMove(choices[0], choices[1]);
        _botMove = playerGk.pickMove();
    }
    else if (_playerRole == GK)
    {
        std::cout << playerGk._getName() << " vs " << playerAtk._getName() << std::endl;
        _playerMove = playerGk.pickMove(choices[0], choices[1]);
        _botMove = playerAtk.pickMove();
    }
    else
    {
        std::cerr << "Wrong handle action used (one of two players is not ATK/GK" << std::endl;
        exit(0);
    }

    float adjustment;

    if (_playerMove._getDirection() == _botMove._getDirection())
        adjustment = 0.2;
    else if (_playerMove._getDirection() - _botMove._getDirection() == 1)
        adjustment = 0.06;
    else
        adjustment = -0.4;

    _playerMove._setAccuracy(_playerMove._getAccuracy() + (_playerRole == ATK ? -adjustment : adjustment));

    std::cout << _playerMove._getAccuracy()
              << " ( - ) "
              << _botMove._getAccuracy()
              << " • bot: "
              << _botMove.toString()
              << std::endl;

    return _playerMove - _botMove;
}