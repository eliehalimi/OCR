#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../SDL/pixel_operations.h"

void take_samples(SDL_Surface *img, size_t x, size_t y, int samples[], int *nbsamples)
{
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
						(*nbsamples)++;
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
						(*nbsamples)++;
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
						(*nbsamples)++;
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
						(*nbsamples)++;
						k++;
						is_sample = 1;
					}
				}
			}
			is_sample = 0;
		}
	}
}

void cut(int samples[], int nbsamples, int left[], int *nbleft, int right[], int *nbright)
{
	for (int i = 0; i < nbsamples; i++)
	{
		if (i <= nbsamples / 2)
		{
			left[i] = samples[i];
		}
		else
		{
			right[i] = samples[i];
		}
	}
	*nbleft = nbsamples / 2;
	*nbright = nbsamples / 2 + 1;
}

void 

void __divacon(SDL_Surface *img, size_t x, size_t y, int samples[], int nbsamples)
{
	if (nbsamples > 2)
	{
		int left[];
		int right[];
		int nbleft = 0;
		int nbright = 0;
		cut(samples, nbsamples, left, &nbleft, right, &nbright);
		__divacon(img, x, y, left, nbleft);
		__divacon(img, x, y, right, nbright);
	}
	int maxleft = 0;
	int maxright= 0;
	for (int i = 0; i < nbleft; i++)
	{
		if(left[maxleft * 2]< left[i*2])
		{
			maxleft = i;
		}
	}
	for (int i = 0; i < nbright; i++)
	{       
		if(left[maxright * 2]< right[i*2])
		{
		        maxright = i;
		}
	}
	int a = (nbright[maxleft * 2] - nbleft[maxleft * 2]) / (nbright[maxright * 2 + 1] - nbleft[maxleft * 2 + 1]);
	int b = nbleft[maxleft * 2 + 1] -  a * nbleft[maxleft * 2];
	int i = 0;
	if (a < 0)
	{
		a = -a;
	}
	while ((i * a + b) < 0)
	{
		i++;
	}
	Uint8 r,g,b;
	int exit = 0;
	while (i < x || (i * a + b) < y || exit == 0)
	{
		Uint32 pixel = getpixel(img, i , (i * a + b));
		SDL_GetRGB(pixel, img->format,&r,&g,&b);
		if (g == 255)
		{
			exit = 1;
		}
		putpixel(img, i , (i * a + b), SDL_MapRGB(img->format, 0, 255,0));
		i++;
	}

}

void divacon(SDL_Surface *img, size_t x, size_t y, int samples[], int nbsamples)
{
		
}
