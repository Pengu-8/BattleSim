//
// Created by 123ye on 30/12/2024.
//
#include <iostream>
#include <conio.h>
#include "menu.h"

void Menu::start_up() {
    std::cout << "Press any key to play" << std::endl;
    bool key_press = false;
    while (!key_press) {
        if (kbhit()) {
            key_press = true;
        }
    }
}
int Menu::play_menu() {
    std::cout << "Elemental Battle Simulator\n1. Play\n2. Exit" << std::endl;
    int inputty = 0;
    while (inputty != 1 || inputty != 2) {
        std::cin >> inputty;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Invalid input. Please enter 1 or 2." << std::endl;
        }
        else if (inputty < 1 || inputty > 2) {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Invalid input. Please enter 1 or 2." << std::endl;
        }

        else if (inputty == 1) {
            std::cout << "play" << std::endl;
            return 1;
        }
        else if (inputty == 2) {
            return 0;
        }
    }
}
