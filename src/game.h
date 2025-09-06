//
// Created by Giovanni Cortes on 05/09/25.
//

#ifndef INC_3DRENDERER_GAME_H
#define INC_3DRENDERER_GAME_H

#include <stdbool.h>

#include <SDL2/SDL.h>

#include "gidreklib/renderer.h"

static const int width = 1024;
static const int height = 768;

bool game_init(void);
void game_run(void);
void game_clean(void);

static Renderer renderer;
static SDL_Renderer *sdl_renderer = NULL;
static SDL_Window *window = NULL;
static SDL_Texture *texture = NULL;
static SDL_Rect rect = { 0 };

static bool running = false;

#endif//INC_3DRENDERER_GAME_H
