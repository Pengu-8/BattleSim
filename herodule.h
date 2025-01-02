//
// Created by 123ye on 30/12/2024.
//

#ifndef HERODULE_H
#define HERODULE_H
#include <iostream>


class Herodule {
public:
    int herodule_type;
    int health;
    int max_health;
    int damage;
    int ultimate_damage;
    int heal;

    Herodule(int Herodule_type, std::string player_name);
    void earth_commands();
    void fire_commands();
    void water_commands();
};



#endif //HERODULE_H
