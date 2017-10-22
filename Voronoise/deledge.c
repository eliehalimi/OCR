#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../SDL/pixel_operations.h"

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

void is_connected(SDL_Surface, size_t x, size_t y, Uint32 p1, Uint32 p2, size_t x1, size_t y1, size_t x2, size_t y2)
{
    Uint8 r1, g1, b1;
    Uint8 r2, g2, b2;
    size_t i;
    size_t j;
    
}
