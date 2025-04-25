#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <ctime>
#include <thread> 
#include <chrono> 
#include "Character.h"
#include "FinalEnemy.h"

using namespace std;

int main() {
    srand(time(0));

    Character hero("Hero", 100, 0, true);

    Character enemy("Enemy", 100, 20);

    sf::SoundBuffer swordBuffer;
    if (!swordBuffer.loadFromFile("resources/sword.wav")) {
        std::cout << "Error loading sound file!" << std::endl;
        return -1;
    }
    sf::Sound swordSound;
    swordSound.setBuffer(swordBuffer);

    sf::SoundBuffer deathBuffer;
    if (!deathBuffer.loadFromFile("resources/death.wav")) {
        std::cout << "Error loading death sound file!" << std::endl;
        return -1;
    }
    sf::Sound deathSound;
    deathSound.setBuffer(deathBuffer);

    int round = 0;

    while (hero.isAlive() && enemy.isAlive()) {
        std::cout << "Select your attack:\n"
            << "[1] Sword (15 dmg / 100%)\n"
            << "[2] Bow (30 dmg / 50%)\n"
            << "[3] Gun (50 dmg / 10%)\n"
            << "[4] Telepathic Attack (80 dmg / 5%)" << std::endl;

        int option;
        std::cin >> option;

        switch (option) {
        case 1:
            hero.setDamage(15, 100);
            break;
        case 2:
            hero.setDamage(30, 50);
            break;
        case 3:
            hero.setDamage(50, 10);
            break;
        case 4:
            hero.setDamage(80, 5);
            break;
        default:
            std::cout << "Invalid option. Try again." << std::endl;
            continue;
        }

        if (option == 4) {
            hero.ultimateAttack();
        }
        else {
            hero.attack(enemy, true);
        }
        swordSound.play();

        if (!enemy.isAlive()) {
            std::cout << "You defeated the enemy!" << std::endl;
            deathSound.play();
            break;
        }

        enemy.attack(hero, false);

        if (!hero.isAlive()) {
            std::cout << "You are DEAD!" << std::endl;
            deathSound.play();
            break;
        }

        std::cout << hero.getStatus() << std::endl;
        std::cout << enemy.getStatus() << std::endl;
    }

    if (hero.isAlive()) {
        std::cout << "\nYou have defeated the first enemy! Prepare to face the Final Boss!" << std::endl;

        string chance;
        std::cout << "Before confronting him, you have the chance to test your fortune in a luck wheel. Do you wish to try it? [y/n]: " << std::endl;
        std::cin >> chance;

        for (char& c : chance) {
            c = toupper(c);
        }

        while (chance != "Y" && chance != "N") {
            std::cout << "Please, select a valid option [y/n]: ";
            std::cin >> chance;

            for (char& c : chance) {
                c = toupper(c);
            }
        }

        if (chance == "Y") {
            std::cout << "You selected yes!" << std::endl;
            hero.luckWheel();
        }
        else {
            std::cout << "You selected no!" << std::endl;
        }

        FinalEnemy finalBoss("Final Boss", 500, 50, 100, 200);

        round = 0;

        while (hero.isAlive() && finalBoss.isAlive()) {
            round++;
            std::cout << "\n--- Final Boss Round " << round << " ---" << std::endl;

            std::cout << "Select your attack:\n[1] Spell (29 dmg)\n[2] Gun (26 dmg)\n[3] Sword (23 dmg)" << std::endl;

            int option;
            std::cin >> option;

            switch (option) {
            case 1:
                hero.setDamage(15, 100);
                break;
            case 2:
                hero.setDamage(30, 50);
                break;
            case 3:
                hero.setDamage(50, 10);
                break;
            case 4:
                hero.setDamage(80, 5);
                break;
            default:
                std::cout << "Invalid option. Try again." << std::endl;
                continue;
            }

            if (option == 4) {
                hero.ultimateAttack();
            }
            else {
                hero.attack(finalBoss, true);
            }
            swordSound.play();

            if (!finalBoss.isAlive()) {
                std::cout << "You defeated the Final Boss!" << std::endl;
                deathSound.play();
                break;
            }

            int enemyChoice = rand() % 3;

            if (enemyChoice == 0) {
                finalBoss.attack(hero);
            }
            else {
                finalBoss.ultimateAttack();
                hero.setHP(hero.getHP() - finalBoss.getInfinityVoidAttack());
            }

            if (!hero.isAlive()) {
                std::cout << "You are DEAD!" << std::endl;
                deathSound.play();
                break;
            }

            std::cout << hero.getStatus() << std::endl;
            std::cout << finalBoss.getStatus() << std::endl;
        }
    }

    std::cout << "GAME ENDED" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(3));

    return 0;
}