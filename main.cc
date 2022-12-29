#include <iostream>
#include <vector>
#include "Classes/Player/ATK/PlayerATK.hh"
#include "Classes/Player/DEF/PlayerDEF.hh"
#include "Classes/Player/GK/PlayerGK.hh"
#include "Classes/Action/Action.hh"
#include "Classes/Team/Team.hh"

void createTeam()
{
    PlayerATK ronaldo("Ronaldo", 7, 81, 92, 85);
    PlayerATK messi("Messi", 10, 91, 84, 88);
    PlayerDEF hakimi("Hakimi", 2, 95, 76, 78);
    PlayerDEF ramos("Ramos", 4, 88, 80, 72);
    PlayerGK bono("Bono", 13, 79, 86);

    vector<PlayerATK> atk{ronaldo, messi};
    vector<PlayerDEF> def{ramos, hakimi};

    Team team(atk, def, bono, "Blue Dragon");
    std::cout << team._getName() << std::endl;
    std::cout << "GEN:" << team._getGenRate() << std::endl;
    std::cout << "ATK:" << team._getAtkRate() << std::endl;
    std::cout << "DEF:" << team._getDefRate() << std::endl;
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
    // _game();

    createTeam();

    return 0;
}