#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../SDL/pixel_operations.h"

int take_samples(SDL_Surface *img, size_t x, size_t y, int samples[])
{
	//int nbsamples = 0;
	int k = 0;
	int is_sample = 0;
	Uint32 pixel;
	Uint8 r, g, b;

	for (size_t i = 0; i < x; i++)
	{
		for (size_t j = 0; j < y; j++)
		{
			pixel = getpixel(img, i, j);
			SDL_GetRGB(pixel, img->format, &r, &g, &b);
			if (r == 255 && g == 255 && b == 255)
			{
				if (i != x - 1)
				{
					pixel = getpixel(img, i + 1, j);
					SDL_GetRGB(pixel, img->format, &r, &g, &b);
					if (r == 0 && g == 0 && b == 0 && !is_sample)
					{
						samples[k * 2] = i;
						samples[1 + k * 2] = j; 
						//nbsamples++;
						k++;
						is_sample = 1;
					}
				}
				if (i != 0)
				{
					pixel = getpixel(img, i - 1, j);
					SDL_GetRGB(pixel, img->format, &r, &g, &b);
					if (r == 0 && g == 0 && b == 0 && !is_sample)
					{
						samples[k * 2] = i;
						samples[1 + k * 2] = j;
						//nbsamples++;
						k++;
						is_sample = 1;
					}
				}
				if (j != y - 1)
				{
					pixel = getpixel(img, i, j + 1);
					SDL_GetRGB(pixel, img->format, &r, &g, &b);
					if (r == 0 && g == 0 && b == 0 && !is_sample)
					{
						samples[k * 2] = i;
						samples[1 + k * 2] = j;
						//nbsamples++;
						k++;
						is_sample = 1;
					}
				}
				if (j != 0)
				{
					pixel = getpixel(img, i, j - 1);
					SDL_GetRGB(pixel, img->format, &r, &g, &b);
					if (r == 0 && g == 0 && b == 0 && !is_sample)
					{
						samples[k * 2] = i;
						samples[1 + k * 2] = j;
						//nbsamples++;
						k++;
						is_sample = 1;
					}
				}
			}
			is_sample = 0;
		}
	}
	return 0;

}
