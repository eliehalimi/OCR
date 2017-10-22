#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../SDL/pixel_operations.h"
#include "dynarray.h"

void is_connected(SDL_Surface *img, size_t x, size_t y, size_t i, size_t j, List l)
{
    if !(i < 0 || j < 0 || i >= x || j >= y && !search_l_coords(l, i, j))
    {
        Uint32 pixel = getpixel(img, i, j);
        Uint8 r, g, b;
        SDL_GetRGB(pixel, img -> format, &r, &g, &b);
        if (r == 255)
        {
            insert_l(&l, x);
            insert_l(&l, y);
            is_connected(img, x, y, i - 1, j, l);
            is_connected(img, x, y, i + 1, j, l);
            is_connected(img, x, y, i, j - 1, l);
            is_connected(img, x, y, i, j + 1, l);
        }
    }
}

void deledge(SDL_Surface *img, size_t x, size_t y, int samples[], int lines[])
{
    Uint32 pixel;
    Uint8 r, g, b;
    size_t i;
    size_t j;

    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            
        }
    }
}
