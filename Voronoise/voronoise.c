#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
#include "SDL/pixel_operations.h"
#include "SDL/pixel.operations.c"

int take_samples[][](SDL_Surface *img, size_t x, size_t y)
{
	int samples[][];
	Uint32 pixel;
	Uint8 r, g, b;

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			pixel = getpixel(img, i, j);
			SDL_GetRGB(pixel, img->format, &r, &g, &b)
		}
	}
}
