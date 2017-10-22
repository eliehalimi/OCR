#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../SDL/pixel_operations.h"
#include "dynarray.h"

void is_connected(SDL_Surface *img, size_t x, size_t y, size_t i, size_t j, List l)
{
    if (!((i >= x || j >= y) && !(search_l_coords(&l, i, j))))
    {
        Uint32 pixel = getpixel(img, i, j);
        Uint8 r, g, b;
        SDL_GetRGB(pixel, img -> format, &r, &g, &b);
        if (r == 0)
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

void deledge(SDL_Surface *img, size_t x, size_t y, int lines[], int samples[], List connections)
{
    Uint32 pixel;
    size_t i;
    size_t j;

    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            if (lines[j + i * y] >= 0)
            {
                if (i != 0)
                {
                    is_connected(img, x, y, i, j, connections);
                    if (search_l_coords(&connections, samples[2 * lines[j + (i - 1) * y]], samples[2 * lines[j + (i - 1) * y] + 1]))
                    {
                        lines[j + (i - 1) * y] = -2;
                        lines[j + i * y] = -2;
                    }
                }
                if (i != x - 1)
                {
                    is_connected(img, x, y, i, j, connections);
                    if (search_l_coords(&connections, samples[2 * lines[j + (i + 1) * y]], samples[2 * lines[j + (i + 1) * y] + 1]))
                    {
                        lines[j + (i + 1) * y] = -2;
                        lines[j + i * y] = -2;
                    }
                }
                if (j != 0)
                {
                    is_connected(img, x, y, i, j, connections);
                    if (search_l_coords(&connections, samples[2 * lines[j - 1 + i * y]], samples[2 * lines[j - 1 + i * y] + 1]))
                    {
                        lines[j - 1 + i * y] = -2;
                        lines[j + i * y] = -2;
                    }
                }
                if (j != y - 1)
                {
                    is_connected(img, x, y, i, j, connections);
                    if (search_l_coords(&connections, samples[2 * lines[j + 1 + i * y]], samples[2 * lines[j + 1 + i * y] + 1]))
                    {
                        lines[j + 1 + i * y] = -2;
                        lines[j + i * y] = -2;
                    }
                }
            }
        }
    }
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            if (lines[j + i * y] == -2)
            {
                pixel = SDL_MapRGB(img -> format, 0, 0, 0);
                putpixel(img, i, j, pixel);
            }
        }
    }
}
