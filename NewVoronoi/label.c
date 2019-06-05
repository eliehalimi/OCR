#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../SDL/pixel_operations.h"

int Root(size_t k, int label[],size_t x,size_t y)
{
  for (size_t i =0; i < x*y;i++)
    {
      if((int)k == label[i])
	{
	  return (int)i;
	}
    }
  return -1;
}

void SetEquivalent(size_t i,size_t k, int label[], size_t x,size_t y)
{
  size_t m = Root(i,label,x,y);
  size_t n = Root(k,label,x,y);
  if (m>n)
    {
      label[m]= n;
    }
  else
    {
      label[n]= m;
    }
}


void labels(SDL_Surface *img, size_t x,size_t y, int label[], int samples[], int *nbsamples, int components[], int *nbcomponents)
{
  size_t i = 0;
  size_t j = 0;
  size_t k = 0;
  
  for (i = 0; i < x*y; i++)
    {
      label[i] = i;
    }
  int is_sample = 0;
  Uint32 pixel;
  Uint8 r, g, b;
  
  for (i = 0; i < x; i++)
    {
      for (j = 0; j < y; j++)
        {
	  pixel = getpixel(img, i, j);
	  SDL_GetRGB(pixel, img->format, &r, &g, &b);
	  if (r == 0 && g == 0 && b == 0)
            {
	      if (j != 0 && i != 0)
                {
                  pixel = getpixel(img, i-1, j - 1);
                  SDL_GetRGB(pixel, img->format, &r, &g, &b);
                  if (r == 255 && g == 255 && b == 255 && !is_sample)
                    {
                      
                    }
                  else
                    {
                      SetEquivalent(i+(j*x),(i-1)+((j-1)*x),label,x,y);
	            }

		}

	      if (j != 0)
                {
                  pixel = getpixel(img, i, j - 1);
                  SDL_GetRGB(pixel, img->format, &r, &g, &b);
                  if (r == 255 && g == 255 && b == 255 && !is_sample)
                    {
                      samples[k * 2] = i;
                      samples[1 + k * 2] = j;
                      (*nbsamples)++;
                      k++;
                      is_sample = 1;
                    }
		  else
                    {
                      SetEquivalent(i+j*x,(i)+(j-1)*x,label,x,y);
                    }

                }
	      if (j != 0 && i != x-1)
                {
                  pixel = getpixel(img, i+1, j - 1);
                  SDL_GetRGB(pixel, img->format, &r, &g, &b);
                  if (r == 255 && g == 255 && b == 255 && !is_sample)
                    {
                      
                    }
                  else
                    {
                      SetEquivalent(i+j*x,(i+1)+(j-1)*x,label,x,y);
	            }

		}

	      if (i != 0)
	        {
                  pixel = getpixel(img, i - 1, j);
                  SDL_GetRGB(pixel, img->format, &r, &g, &b);
                  if (r == 255 && g == 255 && b == 255 && !is_sample)
                    {
                      samples[k * 2] = i;
                      samples[1 + k * 2] = j;
                      (*nbsamples)++;
                      k++;
                      is_sample = 1;
                    }
                  else
                    {
                      SetEquivalent(i+j*x,(i-1)+(j)*x,label,x,y);
                    }

                }

	      if (i != x - 1)
                {
		  pixel = getpixel(img, i + 1, j);
		  SDL_GetRGB(pixel, img->format, &r, &g, &b);
		  if (r == 255 && g == 255 && b == 255 && !is_sample)
                    {
		      samples[k * 2] = i;
		      samples[1 + k * 2] = j;
		      (*nbsamples)++;
		      k++;
		      is_sample = 1;
                    }
		  else
                    {
                      SetEquivalent(i+j*x,(i+1)+(j)*x,label,x,y);
                    }
                }

	      if (j != y-1 && i != 0)
                {
                  pixel = getpixel(img, i-1, j + 1);
                  SDL_GetRGB(pixel, img->format, &r, &g, &b);
                  if (r == 255 && g == 255 && b == 255 && !is_sample)
                    {
		      
                    }
                  else
                    {
                      SetEquivalent(i+j*x,(i-1)+(j+1)*x,label,x,y);
	            }

		}

	      if (j != y - 1)
                {
		  pixel = getpixel(img, i, j + 1);
		  SDL_GetRGB(pixel, img->format, &r, &g, &b);
		  if (r == 255 && g == 255 && b == 255 && !is_sample)
                    {
		      samples[k * 2] = i;
		      samples[1 + k * 2] = j;
		      (*nbsamples)++;
		      k++;
		      is_sample = 1;
                    }
                }
	      if (i != x - 1 && j!= y-1)
                {
                  pixel = getpixel(img, i + 1, j+1);
                  SDL_GetRGB(pixel, img->format, &r, &g, &b);
                  if (r == 255 && g == 255 && b == 255 && !is_sample)
                    {
                      
                    }
                  else
                    {
                      SetEquivalent(i+j*x,(i+1)+(j+1)*x,label,x,y);
                    }
		}
            }
	  is_sample = 0;
        }
    }

  int count = 0;
  int label2;
  for (i = 0;i< x;i++)
    {
      for (j=0;j<y;j++)
	{
	  pixel = getpixel(img, i, j);
	  SDL_GetRGB(pixel, img->format, &r, &g, &b);
	  if (r == 0 && g == 0 && b == 0)
	    {
	      label2 = label[i+j*x];
	      if(label2 ==(int)(i+j*x))
		{
		  label[i+j*x] = count;
		  components[count] = 1;
		  count++;
		}
	      else
		{
		  label[i+j*x] = label[label2];
		  components[label[label2]]++;
		}
	    }
	}
    }
  *nbcomponents = count;
}
