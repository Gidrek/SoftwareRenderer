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
        return false;
    }

    sdl_renderer = SDL_CreateRenderer(window, -1, 0);
    if (!sdl_renderer) {
        SDL_Log("Failed to create SDL Renderer %s\n", SDL_GetError());
        return false;

    }

    renderer_init(&renderer, width, height);
    texture = SDL_CreateTexture(sdl_renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, renderer.width, renderer.height);
    rect.w = 0;
    rect.h = 0;
    rect.w = renderer.width;
    rect.h = renderer.height;

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
    // This is going to be the logic to draw, independient of SDL Renderer
    renderer_clear(&renderer, 0xFF6495ED);
    renderer_draw_pixel(&renderer, 11, 10, 0xFFFF0000);
    renderer_draw_pixel(&renderer, 12, 10, 0xFFFF0000);
    renderer_draw_pixel(&renderer, 13, 10, 0xFFFF0000);
    renderer_draw_pixel(&renderer, 14, 10, 0xFFFF0000);
    renderer_draw_pixel(&renderer, 15, 10, 0xFFFF0000);
    renderer_draw_pixel(&renderer, 11, 11, 0xFFFF0000);
    renderer_draw_pixel(&renderer, 12, 11, 0xFFFF0000);
    renderer_draw_pixel(&renderer, 13, 11, 0xFFFF0000);
    renderer_draw_pixel(&renderer, 14, 11, 0xFFFF0000);
    renderer_draw_pixel(&renderer, 15, 11, 0xFFFF0000);
    renderer_draw_pixel(&renderer, 11, 12, 0xFFFF0000);
    renderer_draw_pixel(&renderer, 12, 12, 0xFFFF0000);
    renderer_draw_pixel(&renderer, 13, 12, 0xFFFF0000);
    renderer_draw_pixel(&renderer, 14, 12, 0xFFFF0000);
    renderer_draw_pixel(&renderer, 15, 12, 0xFFFF0000);


    // Render the SDL texture, where we are going to upload our framebuffer
    SDL_UpdateTexture(texture, &rect, renderer.framebuffer, renderer.width * sizeof(uint32_t));

    SDL_RenderClear(sdl_renderer);
    SDL_RenderCopy(sdl_renderer, texture, NULL, NULL);
    SDL_RenderPresent(sdl_renderer);
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

