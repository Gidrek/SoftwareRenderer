#include <stdio.h>

#include "game.h"

int main(int argv, char **args) {
    if (game_init()) {
        game_run();
    }

    game_clean();

    return 0;
}
