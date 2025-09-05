//
// Created by Giovanni Cortes on 05/09/25.
//

#ifndef INC_3DRENDERER_RENDERER_H
#define INC_3DRENDERER_RENDERER_H

#include <stdint.h>
#include <stdlib.h>

typedef struct {
    uint32_t *framebuffer;
    int width;
    int height;
} Renderer;

// Lifecycle functions
void renderer_init(Renderer *r, int width, int height);
void renderer_cleanup(Renderer *r);

void renderer_clear(Renderer *r, uint32_t color);

void renderer_draw_pixel(Renderer *r, int x, int y, uint32_t color);

#endif//INC_3DRENDERER_RENDERER_H
