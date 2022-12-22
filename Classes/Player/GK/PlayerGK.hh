#include "Player.hh"

class PlayerGK : public Player
{

private:
    int loon;

public:
    Move moveDir();
    PlayerGK(Team team, string name, int number, int rate, int pace, int loon, int stamina);
    ~PlayerGK();
};