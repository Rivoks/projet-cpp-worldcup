#include <iostream>
#include "Classes/Player/ATK/PlayerATK.hh"
#include "Classes/Player/DEF/PlayerDEF.hh"
#include "Classes/Player/GK/PlayerGK.hh"

void test(int a = 0, int b = 0, int c = 0)
{
    std::cout << "a" << a << std::endl;
    std::cout << "b" << b << std::endl;
    std::cout << "c" << c << std::endl;
}

int main()
{
    PlayerATK ronaldo("Ronaldo", 7, 81, 92, 85);
    PlayerATK messi("Messi", 10, 85, 92, 91);
    PlayerDEF hakimi("Hakimi", 2, 95, 76, 78);
    PlayerGK ybono("Bono", 13, 79, 86);

    // std::cout << (hakimi.moveHandle(messi) ? "Not Pass" : "Pass") << std::endl;
    std::cout << (ybono.moveKeep(LEFT, ronaldo) ? "Not Pass" : "Pass") << std::endl;

    return 0;
}