#include <iostream>
#include <vector>
#include "Classes/Player/ATK/PlayerATK.hh"
#include "Classes/Player/DEF/PlayerDEF.hh"
#include "Classes/Player/GK/PlayerGK.hh"

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

int main()
{
    /** List of characters */
    PlayerATK ronaldo("Ronaldo", 7, 81, 92, 85);
    PlayerATK messi("Messi", 10, 85, 92, 91);
    PlayerDEF hakimi("Hakimi", 2, 95, 76, 78);
    PlayerGK bono("Bono", 13, 79, 86);

    vector<PlayerATK> players;

    players.push_back(ronaldo);
    players.push_back(messi);

    int entry = 0;
    std::cout << "Pick a Striker: Ronadlo(0) - Messi(1)" << std::endl;
    std::cin >> entry;

    PlayerATK player1 = players[entry];

    int pickMove;
    int pickDir;

    std::cout << "Choose an action: \n"
              << "0 - Dribble\n"
              << "1 - Shoot\n"
              << std::endl;

    std::cin >> pickMove;

    std::cout << "Choose a direction to dribble: \n"
              << "0 - Left\n"
              << "1 - Center\n"
              << "2 - Right\n"
              << std::endl;

    std::cin >> pickDir;

    Move move1 = player1.pickMove(pickMove, pickDir);
    Move move2 = hakimi.pickMove();

    std::cout << "Move1 Accuracy:\n"
              << move1._getAccuracy()
              << std::endl;

    std::cout << "Move2 Accuracy:\n"
              << move2._getAccuracy()
              << std::endl;

    /**
     * if (move1 - move2)
    {
        std::cout << "Dribble has not passed!" << std::endl;
        return 0;
    }

    std::cout << "Dribble has passed!" << std::endl;

    std::cout << "Choose a direction to shoot: \n"
              << "0 - Left\n"
              << "1 - Center\n"
              << "2 - Right\n"
              << std::endl;
    std::cin >> pickDir;

    bool action2 = player1.moveShoot(intToDirection(pickDir), bono);
    std::cout << (action2 ? "GOOOOAAAAAL!" : "Shoot has not passed!") << std::endl;
     *
     */
    return 0;
}