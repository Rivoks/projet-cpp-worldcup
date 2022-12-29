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

vector<int> Action::chooseAction()
{
    int pickMove;
    int pickDir;

    vector<string> actionNames = getActionNames();

    std::cout << "Choose an action: \n"
              << "0 - " << actionNames[0] << "\n"
              << "1 - " << actionNames[1] << "\n"
              << std::endl;

    std::cin >> pickMove;

    std::cout << "Choose a direction to dribble: \n"
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
    vector<int> choices = chooseAction();
    return handleAction(playerAtk, playerDef, playerGk, choices);
}

bool Action::handleAction(PlayerATK playerAtk, PlayerDEF playerDef, PlayerGK playerGk, vector<int> choices)
{
    if (_playerRole == GK || _botRole == GK)
        return handleActionAtkGk(playerAtk, playerGk, choices);

    return handleActionAtkDef(playerAtk, playerDef, choices);
}

bool Action::handleActionAtkDef(PlayerATK playerAtk, PlayerDEF playerDef, vector<int> choices)
{
    if (_playerRole == ATK)
    {
        _playerMove = playerAtk.pickMove(choices[0], choices[1]);
        _botMove = playerDef.pickMove();
    }
    else if (_playerRole == DEF)
    {
        _playerMove = playerDef.pickMove(choices[0], choices[1]);
        _botMove = playerAtk.pickMove();
    }
    else
    {
        std::cerr << "Wrong handle action used (one of two players is not ATK/DEF" << std::endl;
        exit(0);
    }

    float adjustment = _playerMove._getDirection() == _botMove._getDirection() ? -0.07 : 0.05;

    _playerMove._setAccuracy(_playerMove._getAccuracy() + adjustment);
    return _playerMove - _botMove;
}

bool Action::handleActionAtkGk(PlayerATK playerAtk, PlayerGK playerGk, vector<int> choices)
{
    if (_playerRole == ATK)
    {
        _playerMove = playerAtk.pickMove(choices[0], choices[1]);
        _botMove = playerGk.pickMove();
    }
    else if (_playerRole == GK)
    {
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
        adjustment = -0.12;
    else if (_playerMove._getDirection() - _botMove._getDirection() == 1)
        adjustment = -0.05;
    else
        adjustment = 0.09;

    _playerMove._setAccuracy(_playerMove._getAccuracy() + adjustment);

    return _playerMove - _botMove;
}