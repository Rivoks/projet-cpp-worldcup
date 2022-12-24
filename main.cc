#include <iostream>
#include "Classes/Player/ATK/PlayerATK.hh"
#include "Classes/Player/DEF/PlayerDEF.hh"

int main()
{
    PlayerATK player1("Ronaldo", 7, 81, 92, 85);
    PlayerATK player2("Messi", 10, 85, 92, 91);
    PlayerDEF player3("Hakimi", 2, 95, 76, 78);

    // std::cout << player1 + player2 << std::endl;

    std::cout << player3 - player2 << std::endl;

    return 0;
}