#pragma once
#include <cstdlib>
#include <ctime>
#include <stddef.h>
#include "../Player/ATK/PlayerATK.hh"
#include "../Player/DEF/PlayerDEF.hh"

class Action
{
private:
    Move _move1;
    // Move _move2;
    PlayerRole _playerRole;
    PlayerRole _botRole;

public:
    Action(PlayerRole playerRole, PlayerRole botRole);
    ~Action();
};