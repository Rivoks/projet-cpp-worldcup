#include "Action.hh"

Action::Action(PlayerRole playerRole, PlayerRole botRole) : _move1(0.5)
{
    _playerRole = playerRole;
    _botRole = botRole;
}

Action::~Action()
{
}
