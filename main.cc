#include <iostream>
#include "Classes/Player/ATK/PlayerATK.hh"

int main()
{
    PlayerATK *player1 = new PlayerATK("Ronaldo", 7, 81, 92, 85);

    std::cout << player1->_getName() << std::endl;

    return 0;
}