//
// Created by 123ye on 30/12/2024.
//
#include <iostream>
#include <vector>
#include "game.h"
Game::Game():defend(false), damage_multiplier(1.0) {

}
void Game::herodule_selection() {
    std::cout<< "\n\nRULES\n1. Earth beats Water\n2. Water beats Fire\n3. Fire beats Earth\n\n"<<std::endl;
    // std::cout<< "Select Your Environmental Herodules.\n1. Earth\n2. Fire\n3. Water"<<std::endl;
    // int inputty = 0;
    while (herodules_collection.size() < 3) {
        std::cout<< "Select Your Environmental Herodules.\n1. Earth\n2. Fire\n3. Water"<<std::endl;
        std::cin >> inputty;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Invalid input. Please enter 1,2 or 3" << std::endl;
        }
        else if (inputty == 1 || inputty == 2 || inputty == 3) {
            Herodule herodule(inputty,"Player");
            herodules_collection.push_back(herodule);
        }
        else {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Invalid input. Please enter 1,2 or 3" << std::endl;
        }
    }
    while (bot_collection.size() < 3) {
        bot_selection = (rand() % 5 + 1) / 2 + 1;
        Herodule herodule(bot_selection,"Bot");
        bot_collection.push_back(herodule);
    }
}

void Game::start_game() {
    while (herodules_collection.size() > 0 || bot_collection.size() > 0) {
        std::cout << "Which Herodule Would You like to Play?\nPlayer's Herodules                            Bot's Herodules" << std::endl;
        for (int i = 0 ; i < herodules_collection.size(); i++) {
            std::cout << i+1 << ". " << herodules_collection[i].elemental_class << " | "
            << herodules_collection[i].health << " hp                            "
            << bot_collection[i].elemental_class << " | "
            << bot_collection[i].health << " hp" << std::endl;
        }
        bool selected = false;
        while (!selected) {
            std::cin >> inputty;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                std::cout << "Invalid input. Please enter 1,2 or 3" << std::endl;
            }
            else if (inputty == 1 || inputty == 2 || inputty == 3) {
                selected = true;
            }
            else {
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                std::cout << "Invalid input. Please enter 1,2 or 3" << std::endl;
            }
        }

        Herodule* playing_hero = &herodules_collection[inputty - 1];
        bot_selection = (rand() % 5 + 1) / 2;
        Herodule* bot_hero = &bot_collection[bot_selection];
        std::cout << "Player is playing " << playing_hero->elemental_class <<". Bot is playing " << bot_hero->elemental_class << std::endl;
        if (playing_hero->herodule_type == 1 && bot_hero->herodule_type == 2
            || playing_hero->herodule_type == 2 && bot_hero->herodule_type == 3
            || playing_hero->herodule_type == 3 && bot_hero->herodule_type == 1) {
            damage_multiplier = 0.6;
        }
        else if (playing_hero->herodule_type == 1 && bot_hero->herodule_type == 3
            || playing_hero->herodule_type == 2 && bot_hero->herodule_type == 1
            || playing_hero->herodule_type == 3 && bot_hero->herodule_type == 2) {
            damage_multiplier = 1.4;
        }
        else {
            damage_multiplier = 1.0;
        }

        selected = false;
        while (!selected) {
            std::cout << "What Would You Like to Do?\n1. Attack\n2. Defend\n3. Heal\n" << std::endl;
            std::cin >> inputty;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                std::cout << "Invalid input. Please enter 1,2 or 3" << std::endl;
            }
            else if (inputty == 1) {
                bot_hero->health -= playing_hero->damage * damage_multiplier;
                bot_hero->health = std::max(bot_hero->health, bot_hero->min_health);
                std::cout << "Player damaged the bot by " << playing_hero->damage * damage_multiplier <<" and left the bot with "
                << bot_hero->health << "hp" << std::endl;
                selected = true;
            }
            else if (inputty == 2) {
                defend = true;
                std::cout << "Player is defending" << std::endl;
                selected = true;
            }
            else if (inputty == 3) {
                playing_hero->health += playing_hero->heal;
                playing_hero->health = std::min(playing_hero->health, playing_hero->max_health);
                std::cout << "Player healed " << playing_hero->heal <<"hp and now has "<< playing_hero->health << "hp"<< std::endl;
                selected = true;
            }
            else {
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                std::cout << "Invalid input. Please enter 1,2 or 3" << std::endl;
            }
        }
        // bot_action = (rand() % 5 + 1) / 2;

    }
    if (herodules_collection.size() > 0) {
        std::cout <<"Player Wins!"<< std::endl;
    }
    else {
        std::cout <<"Bot Wins!"<< std::endl;
    }
}
