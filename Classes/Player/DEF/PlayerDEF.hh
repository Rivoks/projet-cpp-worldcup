#include "Player.hh"

class PlayerDEF : public Player
{

private:
    int def;
    int stamina;

public:
    Move moveDir();
    Move moveTackle();
    PlayerDEF(Team team, string name, int number, int rate, int pace, int def, int stamina);
    ~PlayerDEF();
};