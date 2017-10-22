# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include <assert.h>
# include <err.h>
# include <stdio.h>
# include <stdlib.h>
# include "../SDL/pixel_operations.h"

void green(SDL_Surface *img, size_t i, size_t j)
{
  Uint32 pixel = SDL_MapRGB(img->format,0,255,0);
  putpixel(img,i,j,pixel);
}

int sq(int x, int y)
{
  return x * x + y*y;
}

void bruteforce(SDL_Surface *img, size_t x, size_t y, int samples[], int nbsamples, int lines[])
{
  int exit =0;
  int d;
  int d2;
  int p;
  for (size_t i = 0; i < x; i++)
    {
      for (size_t j = 0; j < y; j++)
	{
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
		  d2 = sq(i - samples[k*2],j - samples[2*k+1]);
		  if (d2< d)
		    {
		      d = d2;
		      p = k;
		    }
		}
	      lines[j+i*y] = p;
	    }
	}
    }
}

void drawgreen(SDL_Surface *img, size_t x, size_t y, int lines[])
{
  int left  = 0;
  int right = 0;
  int up = 0;
  int down = 0;
  for (size_t i = 0; i< x;i++)
    {
      for (size_t j = 0; j< y; j++)
	{
	  left = 0;
	  right = 0;
	  up = 0;
	  down = 0;
	  if (lines[j + i*y] != -1)
	    {
	      if (j+1 < y)
		{
		  if (lines[j+1 + i*y] != -1)
		    {
		      if(lines [j+1 + i*y] != lines[j + i*y])
			{
			  green(img, i , j);
			}
		    }
		  else
		    {
		      down = 1;
		    }
		}
	      if (j-1 > 0)
                {
                  if (lines[j-1 + i*y] == -1)
                    {
                      up = 1;
                    }
                }
	      if (i+1 < x)
                {
                  if (lines[j + (i+1)*y] != -1)
                    {
                      if(lines [j + (i+1)*y] != lines[j + i*y])
                        {
                          green(img, i , j);
                        }
                    }
                  else
                    {
                      right = 1;
                    }
                }	
	      if (i-1 > 0)
		{
                  if (lines[j + (i-1)*y] == -1)
                    {
		      left = 1;
		    }
                }
	      
	      if ((left == 1 && right ==1) || (up == 1 && down == 1))
		{
		  green(img,i,j);
		}
	    }

	}
    }
}
