#include "FinalEnemy.h"
#pragma once
using namespace std;
#include <algorithm>
#include <iostream> // Asegúrate de incluir este encabezado

FinalEnemy::FinalEnemy(string name, int hp, int damage, int darknessAttack, int infinityVoidAttack)
    : Character(name, hp, damage, false),
    darknessAttack(darknessAttack),
    infinityVoidAttack(infinityVoidAttack) {
}

int FinalEnemy::getDarknessAttack() {
    return darknessAttack;
}

void FinalEnemy::setDarknessAttack(int darknessAttack) {
    this->darknessAttack = darknessAttack;
}

int FinalEnemy::getInfinityVoidAttack() {
    return infinityVoidAttack;
}

void FinalEnemy::setInfinityVoidAttack(int infinityVoidAttack) {
    this->infinityVoidAttack = infinityVoidAttack;
}

void FinalEnemy::attack(Character& target, bool isHero) {
    if (!isHero) {
        int totalDamage = getDamage() + darknessAttack;
        int newHP = target.getHP() - totalDamage;
        target.setHP(max(0, newHP));
        cout << getName() << " uses Darkness Attack and deals " << totalDamage << " damage!" << endl;
    }
}

void FinalEnemy::ultimateAttack() {
    cout << getName() << " unleashes Infinity Void Attack, dealing "
        << infinityVoidAttack << " damage to all enemies!" << endl;
}

void FinalEnemy::printAllStatus() {
    cout << "Final Enemy: " << getName() << endl;
    cout << "HP: " << getHP() << endl;
    cout << "Damage: " << getDamage() << endl;
    cout << "Darkness Attack: " << getDarknessAttack() << endl;
    cout << "Infinity Void Attack: " << getInfinityVoidAttack() << endl;
	cout << "\n";
}