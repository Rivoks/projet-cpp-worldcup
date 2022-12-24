#include <iostream>
#include "Classes/Player/ATK/PlayerATK.hh"

int main()
{
    PlayerATK player1("Ronaldo", 7, 81, 92, 85);
    PlayerATK player2("Messi", 10, 85, 92, 91);
    PlayerATK player3("Hakimi", 2, 99, 99, 99);

    std::cout << player1 + player2 << std::endl;

    return 0;
}