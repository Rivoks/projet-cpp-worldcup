#include "../Player.hh"

class PlayerATK : public Player
{

private:
    int _shoot;
    int _skill;

public:
    int _getShoot();
    int _getSkill();

    Move moveDir(Direction direction);
    Move moveShoot(Direction direction);
    PlayerATK(string name, int number, int pace, int shoot, int skill);
    ~PlayerATK();
};