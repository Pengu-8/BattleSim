//
// Created by 123ye on 30/12/2024.
//
#include <iostream>
#include <vector>
#include "game.h"


void Game::herodule_selection() {
    std::cout<< "\n\nRULES\n1. Earth beats Water\n2. Water beats Fire\n3. Fire beats Earth\n\n"<<std::endl;
    std::cout<< "Select Your Environmental Herodules.\n1. Earth\n2. Fire\n3. Water"<<std::endl;
    // int inputty = 0;
    while (herodules_collection.size() < 3) {
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
    }
    while (bot_collection.size() < 3) {
        bot_selection = (rand() % 5 + 1) / 2 + 1;
        Herodule herodule(bot_selection,"Bot");
        bot_collection.push_back(herodule);
    }
}
