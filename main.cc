#include <iostream>
#include <vector>
#include "Classes/Player/ATK/PlayerATK.hh"
#include "Classes/Player/DEF/PlayerDEF.hh"
#include "Classes/Player/GK/PlayerGK.hh"
#include "Classes/Action/Action.hh"

Direction intToDirection(int input)
{
    switch (input % 3)
    {
    case 0:
        return LEFT;

    case 1:
        return CENTER;

    default:
        return RIGHT;
    }
}

void _game()
{
    PlayerATK ronaldo("Ronaldo", 7, 81, 92, 85);
    PlayerDEF hakimi("Hakimi", 2, 95, 76, 78);
    PlayerGK bono("Bono", 13, 79, 86);

    int role = 0;
    std::cout << "Pick a Role:\n"
              << "0 - ATK\n"
              << "1 - DEF\n"
              << "2 - GK\n"
              << std::endl;
    std::cin >> role;

    if (role == 0) // Picked ATK
    {
        Action action1(ATK, DEF);
        if (action1.startAction(ronaldo, hakimi, bono))
            std::cout << "Goooooaaaaaal!" << std::endl;
        else
            std::cout << "Oh no! You missed this action..." << std::endl;
    }
    else if (role == 1) // Picked DEF
    {
        Action action1(DEF, ATK);
        if (action1.startAction(ronaldo, hakimi, bono))
            std::cout << "Goooooaaaaaal!" << std::endl;
        else
            std::cout << "Oh no! The opponent passed..." << std::endl;
    }
    else
    {
        Action action1(GK, ATK);
        if (action1.startAction(ronaldo, hakimi, bono))
            std::cout << "What a miraculous save!" << std::endl;
        else
            std::cout << "Goooaaaal! The opponent scored!" << std::endl;
    }
}

int main()
{
    _game();

    return 0;
}