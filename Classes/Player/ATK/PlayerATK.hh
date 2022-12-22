#include "Player.hh"

class PlayerATK : public Player
{

private:
    int shoot;
    int skill;

public:
    Move moveDir();
    Move moveShoot();
    PlayerATK(Team team, string name, int number, int rate, int pace, int shoot, int skill);
    ~PlayerATK();
};