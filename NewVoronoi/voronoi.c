# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include <assert.h>
# include <err.h>
# include <stdio.h>
# include <stdlib.h>
# include "../SDL/pixel_operations.h"
# include "struct.h"

void merge(SDL_Surface *img, struct edge *e)
{
  struct edge *tmpe = e->next;
  struct point *tmpp;
  int i,j;
  Uint32 pixel = SDL_MapRGB(img->format,255,0,255);
  while(tmpe != NULL)
    {
      tmpp = tmpe->point->next;
      while(tmpp != NULL)
	{
	  i = tmpp->x;
	  j = tmpp->y;
	  putpixel(img, i, j, pixel);
	  
	}
      tmpe = tmpe->next;
    }
}

