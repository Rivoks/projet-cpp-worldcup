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
    PlayerATK messi("Messi", 10, 85, 92, 91);
    PlayerDEF hakimi("Hakimi", 2, 95, 76, 78);
    PlayerGK bono("Bono", 13, 79, 86);

    vector<PlayerATK> playerSelections;

    playerSelections.push_back(ronaldo);
    playerSelections.push_back(messi);

    int entry = 0;
    std::cout << "Pick a Striker:\n"
              << "0 - Ronaldo\n"
              << "1 - Messi\n"
              << std::endl;
    std::cin >> entry;

    PlayerATK player = playerSelections[entry];

    Action action1(player._getRole(), hakimi._getRole());

    if (action1.startAction(player, hakimi, bono))
        std::cout << "Goooooaaaaaal!" << std::endl;
    else
        std::cout << "Oh no! You missed this action..." << std::endl;
}

int main()
{
    _game();

    return 0;
}