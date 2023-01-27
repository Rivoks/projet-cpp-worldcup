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
    // An action is a confrontation between two players
    Move _playerMove; // We have the move of our player against the move of the "bot"
    Move _botMove;
    PlayerRole _playerRole; // It is important to have the role of the two players. For example, a DEF can not play against a GK
    PlayerRole _botRole;

public:
    vector<string> getActionNames(); // Each role have several potential action, for example an ATK can dribble or shoot
    vector<int> chooseAction(int move = -1); // The player have to choose what he is going to do against his opponent

    bool handleAction(PlayerATK playerAtk, PlayerDEF playerDef, PlayerGK playerGK); // The function that leads all the action
    bool handleActionAtkDef(PlayerATK playerAtk, PlayerDEF playerDef, vector<int> choices); // Action between an ATK and a DEF
    bool handleActionAtkGk(PlayerATK playerAtk, PlayerGK playerGk, vector<int> choices); // Action between an ATK and a GK

    bool startAction(PlayerATK playerAtk, PlayerDEF playerDef, PlayerGK playerGk); // Start of the action if it is authorized

    Action(PlayerRole playerRole, PlayerRole botRole);
    ~Action();
};