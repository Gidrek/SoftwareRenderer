//
// Created by Giovanni Cortes on 05/09/25.
//

#include "renderer.h"


void renderer_init(Renderer *r, int width, int height) {

    if (!r || width <= 0 || height <= 0) {
        return;
    }

    r->width = width;
    r->height = height;
    r->framebuffer = (uint32_t *) calloc(width * height, sizeof(uint32_t));

}

void renderer_cleanup(Renderer *r) {
    if (!r) {
        return;
    }

    if (r->framebuffer) {
        free(r->framebuffer);
        r->framebuffer = NULL;
    }
    r->width = 0;
    r->height = 0;
}

void renderer_clear(Renderer *r, uint32_t color) {
    if (!r || !r->framebuffer) {
        return;
    }

    for (int i = 0; i < r->width * r->height; i++) {
        r->framebuffer[i] = color;
    }
}

void renderer_draw_pixel(Renderer *r, int x, int y, uint32_t color) {
    if (!r) {
        return;
    }

    if (x < 0 || x > r->width || y < 0 || y > r->height) {
        return;
    }

    r->framebuffer[(y * r->width) + x] = color;
}