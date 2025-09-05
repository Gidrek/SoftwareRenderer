//
// Created by Giovanni Cortes on 05/09/25.
//

#include "game.h"

bool game_init(void) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("Failed to initialize SDL: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow(
            "Software Renderer (SDL2, C)",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            width, height,
            SDL_WINDOW_SHOWN);

    if (!window) {
        SDL_Log("Failed to create SDL Window: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }

    renderer_init(&renderer, 4, 4);

    running = true;
    return true;

}

void game_process_input(void) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        }
    }
}

void game_update(void) {
// TODO: Update game logic
}

void game_draw(void) {
    renderer_clear(&renderer, 0xFF000000);
}

void game_run(void) {
    while (running) {
        game_process_input();
        game_update();
        game_draw();
    }
}

void game_clean(void) {
    renderer_cleanup(&renderer);
    SDL_DestroyRenderer(sdl_renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

