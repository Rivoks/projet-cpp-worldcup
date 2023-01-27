#pragma once
#include "PlayerATK.hh"

class Showman : public PlayerATK
{

private:
    string _celebration;

public:
    string _getCelebration();

    Showman(string name, int number, int pace, int shoot, int skill, string celebration);
    virtual ~Showman(); // Virtual destructor
};