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
    void herodule_selection();
};



#endif //GAME_H
