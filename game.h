//
// Created by 123ye on 30/12/2024.
//

#ifndef GAME_H
#define GAME_H
#include "herodule.h"
#include <vector>

class Game {
public:
    std::vector<Herodule> herodules_collection;
    std::vector<Herodule> bot_collection;
    int inputty;
    int bot_selection;
    // Herodule playing_hero;
    // Herodule bot_hero;
    void herodule_selection();
    void start_game();
};



#endif //GAME_H
