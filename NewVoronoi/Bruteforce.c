# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include <assert.h>
# include <err.h>
# include <stdio.h>
# include <stdlib.h>
# include "../SDL/pixel_operations.h"
# include "struct.h"

int sq(int x, int y)
{
  return x * x + y*y;
}

void bruteforce(SDL_Surface *img, size_t x, size_t y, int samples[], int nbsamples, int lines[], int label[], struct edge *e)
{
  struct edge *tmp = e;
  int exit =0;
  int d;
  int d2;
  int p;
  int visited = 0;
  for (size_t i = 0; i < x; i++)
    {
      for (size_t j = 0; j < y; j++)
	{
	  printf("%ld",i);
          printf("%ld\n",j);
	  Uint8 r,g,b;
	  Uint32 pixel = getpixel(img, i, j);
	  SDL_GetRGB(pixel, img->format,&r,&g,&b);
	  exit = 0;
	  if (r == 0)
	    {
	      exit = 1;
	    }
	  if (exit == 0)
	    {
	      d = sq(samples[0],samples[1]);
	      p = 0;
	      for (int k = 0; k < nbsamples; k++)
		{
		  printf("%d\n",k);
		  d2 = sq(i - samples[k*2],j - samples[2*k+1]);
		  if (d2< d)
		    {
		      d = d2;
		      p = label[samples[k*2]+samples[2*k+1]*x];
		    }
		}
	      lines[i+j*x] = p;
	      visited = 0;
	      if (i != 0)
		{
		  if (lines[i-1+j*x] != p && lines[i-1+j*x] != -1)
		    {
		      add_point(tmp,i,j,lines[i-1+j*x],p);
		      visited = 1;
		    }
		}
	      if (j != 0 && visited == 0)
		{
		  if (lines[i+(j-1)*x] != p && lines[i+(j-1)*x] != -1)
		    {
		      add_point(tmp,i,j,lines[i+(j-1)*x],p);
		      visited = 1;
		    }
		}
	    }
	}
    }
}
