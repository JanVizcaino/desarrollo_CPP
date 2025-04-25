#pragma once
#include <string>
using namespace std;

class Character {
protected:
    string name;
    int hp;
    int damage;
    bool isHeroCharacter;
    int successProbability;

public:
    Character();
    Character(string name, int hp, int damage, bool isHeroCharacter = false);
    string getName();
    void setName(string name);
    int getHP();
    void setHP(int HP);
    int getDamage();
    void setDamage(int damage, int successProbability);
    bool attackSuccess();
    virtual string getStatus();
    virtual void attack(Character& target, bool isHero = false);
    virtual void ultimateAttack();
    bool isAlive();
    bool isHero();
    void luckWheel();
};