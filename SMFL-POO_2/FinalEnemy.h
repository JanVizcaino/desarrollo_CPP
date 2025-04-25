#pragma once
#include "Character.h"
#include <iostream>
using namespace std;

class FinalEnemy : public Character {
private:
    int darknessAttack;
    int infinityVoidAttack;

public:
    FinalEnemy(string name, int hp, int damage, int darknessAttack, int infinityVoidAttack);

    int getDarknessAttack();
    void setDarknessAttack(int darknessAttack);

    int getInfinityVoidAttack();
    void setInfinityVoidAttack(int infinityVoidAttack);

    void attack(Character& target, bool isHero = false) override;
    void ultimateAttack() override;

    void printAllStatus();
};