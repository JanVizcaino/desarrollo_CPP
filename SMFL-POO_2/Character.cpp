#include "Character.h"
#include <iostream>
#include <algorithm>
using namespace std;

Character::Character(string name, int hp, int damage, bool isHeroCharacter)
    : name(name), hp(hp), damage(damage), isHeroCharacter(isHeroCharacter) {
}

string Character::getName() {
    return name;
}

int Character::getHP() {
    return hp;
}

int Character::getDamage() {
    return damage;
}

void Character::setHP(int HP) {
    hp = HP;
}

void Character::setDamage(int damage, int successProbability) {
    this->damage = damage;
    this->successProbability = successProbability;
}

bool Character::attackSuccess() {
    int chance = rand() % 100;
    return chance < successProbability;
}

string Character::getStatus() {
    return "Name: " + name + "\nHP: " + to_string(hp) + "\nDamage: " + to_string(damage) + ". \n"; 
}

void Character::attack(Character& target, bool isHero) {
    if (!isHero || attackSuccess()) {
        int newHP = target.getHP() - damage;
        target.setHP(max(0, newHP));
        cout << name << " attacks " << target.getName() << " and deals " << damage << " damage!" << endl;
    }
    else {
        cout << name << "'s attack missed!" << endl;
    }
}

void Character::ultimateAttack() {
    int probabilityUlti = rand() % 11;
    int finalDamage = damage;

    if (probabilityUlti < 3) {
        cout << "Lucky! " << name << "'s attack is doubled!" << endl;
        finalDamage *= 2;
    }

    if (attackSuccess()) {
        cout << name << " uses Ultimate Attack and deals " << finalDamage << " damage!" << endl;
    }
    else {
        cout << name << "'s Ultimate Attack missed!" << endl;
    }
}

bool Character::isAlive() {
    return hp > 0;
}

bool Character::isHero() {
    return isHeroCharacter;
}

void Character::luckWheel() {
    int chance = rand() % 100 + 1;
    cout << "Spinning the luck wheel...\n";

    if (chance <= 5) {
        cout << name << " lost the luck wheel... you are DEAD!\n";
        hp = 0;
    }
    else if (chance <= 85) {
        int lifeGained = rand() % 20 * 4;
        hp += lifeGained;
        cout << name << " won life! Gained " << lifeGained << " HP.\n";
    }
    else {
        damage *= 3;
        cout << name << " got stronger! Damage is now triplicated!\n";
    }
}