#pragma once
#include <cstdlib>
#include <ctime>
#include <stddef.h>
#include "../Player/ATK/PlayerATK.hh"
#include "../Player/DEF/PlayerDEF.hh"
#include "../Player/GK/PlayerGK.hh"

class Action
{
private:
    Move _playerMove;
    Move _botMove;
    PlayerRole _playerRole;
    PlayerRole _botRole;

public:
    vector<string> getActionNames();
    vector<int> chooseAction();

    bool handleAction(PlayerATK playerAtk, PlayerDEF playerDef, PlayerGK playerGK, vector<int> choices);
    bool handleActionAtkDef(PlayerATK playerAtk, PlayerDEF playerDef, vector<int> choices);
    bool handleActionAtkGk(PlayerATK playerAtk, PlayerGK playerGk, vector<int> choices);

    bool startAction(PlayerATK playerAtk, PlayerDEF playerDef, PlayerGK playerGk);

    Action(PlayerRole playerRole, PlayerRole botRole);
    ~Action();
};