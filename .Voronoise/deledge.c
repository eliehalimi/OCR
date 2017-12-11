#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../SDL/pixel_operations.h"
#include "dynarray.h"

void white(SDL_Surface *img, size_t i, size_t j)
{
  Uint32 pixel = SDL_MapRGB(img->format,255,255,255);
  putpixel(img,i,j,pixel);
}


int is_connected(SDL_Surface *img, size_t x, size_t y, size_t i, size_t j, size_t i2, size_t j2, List *l)
{
    if (!((i >= x || j >= y) && !(search_l_coords(l, i, j))))
    {
        Uint32 pixel = getpixel(img, i, j);
        Uint8 r, g, b;
        SDL_GetRGB(pixel, img -> format, &r, &g, &b);
	if (i == i2 && j == j2)
	  {
	    return 1;
	  }
	
	if (r == 0)
        {
	  insert_l(l,i);
	  insert_l(l,j);
	  
	  return is_connected(img, x, y, i - 1, j,i2,j2, l) || is_connected(img, x, y, i + 1, j,i2,j2, l) || is_connected(img, x, y, i, j - 1,i2,j2, l) || is_connected(img, x, y, i, j + 1,i2,j2, l);
        }
    }
    return 0;
}

void deledge(SDL_Surface *img, size_t x, size_t y, int lines[], int samples[])
{
  int left  = 0;
  int right = 0;
  int up = 0;
  int down = 0;
  List l;
  init_l(&l,1);
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
			if(is_connected(img, x,y,samples[2*lines[j+1+i*y]],samples[1+2*lines[j+1+i*y]],samples[2*lines[j+i*y]],samples[1+2*lines[j+i*y]], &l))
			  {
			    init_l(&l,1);
			    lines[j+1+i*y] = lines[j+i*y];
			    white(img,i,j);
			  }
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
			if(is_connected(img, x,y,samples[2*lines[j+(i+1)*y]],samples[1+2*lines[j+(i+1)*y]],samples[2*lines[j+i*y]],samples[1+2*lines[j+i*y]], &l))
			  {
			    init_l(&l,1);
			    lines[j+(i+1)*y] = lines[j+i*y];
			    white(img,i,j);
			  }
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
		white(img,i,j);
	      }
	  }
	  
        }
    }
}


/*void deledge(SDL_Surface *img, size_t x, size_t y, int lines[], int samples[],int nbsamples, List connections)
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
*/
