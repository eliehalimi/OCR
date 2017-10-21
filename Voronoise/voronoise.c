#include <stdio.h>478
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
#include "SDL/pixel_operations.h"
#include "SDL/pixel.operations.c"

int take_samples(SDL_Surface *img, size_t x, size_t y, int samples[][])
{
	int nbsamples = 0;
	int k = 0;
	Uint32 pixel;
	Uint8 r, g, b;

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			pixel = getpixel(img, i, j);
			SDL_GetRGB(pixel, img->format, &r, &g, &b);
			if (r == 255 && g == 255 && b == 255)
			{
				if (i != x - 1)
				{
					pixel = getpixel(img, i + 1, j);
					SDL_GetRGB(pixel, img->format, &r, &g, &b);
					if (r == 0 && g == 0 && b == 0)
					{
						samples[k][0] = i;
						samples[k][1] = j;
						nbsamples++;
						k++;
					}
				}
				if (i != 0)
				{
					pixel = getpixel(img, i - 1, j);
					SDL_GetRGB(pixel, img->format, &r, &g, &b);
					if (r == 0 && g == 0 && b == 0)
					{
						samples[k][0] = i;
						samples[k][1] = j;
						nbsamples++;
						k++;
					}
				}
				if (j != y - 1)
				{
					pixel = getpixel(img, i, j + 1);
					SDL_GetRGB(pixel, img->format, &r, &g, &b);
					if (r == 0 && g == 0 && b == 0)
					{
						samples[k][0] = i;
						samples[k][1] = j;
						nbsamples++;
						k++;
					}
				}
				if (j != 0)
				{
					pixel = getpixel(img, i, j + 1);
					SDL_GetRGB(pixel, img->format, &r, &g, &b);
					if (r == 0 && g == 0 && b == 0)
					{
						samples[k][0] = i;
						samples[k][1] = j;
						nbsamples++;
						k++;
					}
				}
			}
		}
	}
	return nbsamples;
}
