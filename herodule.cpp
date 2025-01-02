//
// Created by 123ye on 30/12/2024.
//
#include <iostream>
#include "herodule.h"

Herodule::Herodule(int Herodule_type, std::string player_name):health(5000),max_health(6500),damage(1420),ultimate_damage(2200),heal(590) {
    switch (Herodule_type) {
        case 1:
            std::cout << player_name << " has selected Earth"<< std::endl;
            herodule_type = 1;
            break;
        case 2:
            std::cout << player_name << " has selected Fire"<< std::endl;
            herodule_type = 2;
            break;
        case 3:
            std::cout << player_name << " has selected Water"<< std::endl;
            herodule_type = 3;
            break;
        default:
            std::cout <<"Error"<< std::endl;
            break;
    }
}

void Herodule::earth_commands() {

}

void Herodule::fire_commands() {

}

void Herodule::water_commands() {

}