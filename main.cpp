#include <iostream>

#include "menu.h"
#include "game.h"

using namespace std;

int main() {
    srand(time(NULL));
    Menu::start_up();
    int exit_value = Menu::play_menu();
    if (exit_value == 0) {
        return 0;
    }
    Game game;
    game.herodule_selection();

    return 0;
}
