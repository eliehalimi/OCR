#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../SDL/pixel_operations.h"
#include <unistd.h>
#include "label.h"

void add_comp(struct components *c, size_t x, size_t y)
{
  struct components *tmp = c;
  while (tmp->next != NULL)
    {
      tmp = tmp->next;
    }
  tmp->next = malloc(sizeof(struct components));
  tmp->next->up = y;
  tmp->next->down = y;
  tmp->next->left = x;
  tmp->next->right = x;
  tmp->next->next=NULL;
}


void compare(struct components *c,size_t x, size_t y, int i)
{
  struct components *tmp = c;
  for (int k = 0; k <= i;k++)
    {
      tmp = tmp->next;
    }
  if (tmp->up > y)
    {
      tmp->up = y;
    }
  if(tmp->down < y)
    {
      tmp->down = y;
    }
  if(tmp->left > x)
    {
      tmp->left = x;
    }
  if(tmp->right < x)
    {
      tmp->right = x;
    }
}

void add_image(int label[], struct components *c, struct images *images)
{
  write(1,"COUCOU\n",7);
  struct components *tmp = c;
  struct images *tmpim = images;
  while(tmp->next != NULL)
    {
      write(1,"COUCO6\n",7);
      int y = (int)tmp->next->down - (int)tmp->next->up +1;
      int x = (int)tmp->next->right - (int)tmp->next->left +1;
      printf("%d",x);
      printf("%d",y);
      
      write(1,"COUCO9\n",7);
      tmpim->next = malloc(sizeof(struct images));
      tmpim->next->next = NULL;
      tmpim->next->image = malloc(sizeof(int)*x*y);
      for(size_t j = tmp->next->up;j <= tmp->next->down; j++)
	{
	  for(size_t i = tmp->next->left; i <= tmp->next->right; i++)
	    {
	      *(tmpim->next->image + ((int)i-(int)(tmp->next->left)) + (((int)j-(int)(tmp->next->up))*x)) = (label[i +j*x]==-1);
	    }
	}
      tmpim->next->x =x;
      tmpim->next->y =y;
      tmpim = tmpim->next;
      tmp = tmp->next;
      write(1,"COUCO10\n",8);
    }
}


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


struct images* labels(SDL_Surface *img, size_t x,size_t y, int label[])
{
  write(1,"COUCOU\n",7);

  size_t i = 0;
  size_t j = 0;
  for (i = 0; i < x*y; i++)
    {
      label[i] = i;
    }
  Uint32 pixel;
  Uint8 r, g, b;
  
  for (j = 0; j < y; j++)
    {
      for (i = 0; i < x; i++)
        {
	  pixel = getpixel(img, i, j);
	  SDL_GetRGB(pixel, img->format, &r, &g, &b);
	  if (r == 0 && g == 0 && b == 0)
            {
	      if (j != 0 && i != 0)
                {
                  pixel = getpixel(img, i-1, j - 1);
                  SDL_GetRGB(pixel, img->format, &r, &g, &b);
                  if (r == 255 && g == 255 && b == 255)
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
                  if (r == 255 && g == 255 && b == 255)
                    {
                    }
		  else
                    {
                      SetEquivalent(i+j*x,i+(j-1)*x,label,x,y);
                    }

                }
	      if (j != 0 && i != x-1)
                {
                  pixel = getpixel(img, i+1, j - 1);
                  SDL_GetRGB(pixel, img->format, &r, &g, &b);
                  if (r == 255 && g == 255 && b == 255)
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
                  if (r == 255 && g == 255 && b == 255)
                    {
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
		  if (r == 255 && g == 255 && b == 255)
                    {
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
                  if (r == 255 && g == 255 && b == 255)
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
		  if (r == 255 && g == 255 && b == 255)
                    {
                    }
                }
	      if (i != x - 1 && j!= y-1)
                {
                  pixel = getpixel(img, i + 1, j+1);
                  SDL_GetRGB(pixel, img->format, &r, &g, &b);
                  if (r == 255 && g == 255 && b == 255)
                    {
                      
                    }
                  else
                    {
                      SetEquivalent(i+j*x,(i+1)+(j+1)*x,label,x,y);
                    }
		}
            }
	  else
	    {
	      label[i + j*x] = -1;
	    }
        }
    }
  write(1,"COUCOU\n",7);
  size_t count = 0;
  int label2;
  struct components *c = malloc(sizeof(struct components));
  c->next = NULL;
  c->up = 0;
  c->down = 0;
  c->left = 0;
  c->right = 0;
  for (j = 0;j< y;j++)
    {
      for (i=0;i<x;i++)
	{
	  pixel = getpixel(img, i, j);
	  SDL_GetRGB(pixel, img->format, &r, &g, &b);
	  if (r == 0 && g == 0 && b == 0)
	    {
	      label2 = label[i+j*x];
	      write(1,"LABEL\n",6);
	      if(label2 == (int)(i+j*x))
		{
		  write(1,"CONDITION\n",10);
		  label[i+j*x] = count;
		  count++;
		  write(1,"ADD\n",4);
		  add_comp(c,i,j);
		  printf("%ld",c->next->up);
		  printf("%ld",c->next->down);
		  printf("%ld",c->next->left);
		  printf("%ld",c->next->right);

		}
	      else
		{
		  label[i+j*x] = label[label2];
		  compare(c,i,j,label[i+j*x]);
		}
	    }
	}
    }
  write(1,"COUCOU\n",7);
  struct images *images= malloc(sizeof(struct images));
  images->next = NULL;
  images->image = NULL;
  images->x = 0;
  images->y = 0;
  add_image(label,c, images);
  write(1,"add\n",4);

  struct components *tmp = c->next;
  while(c->next != NULL)
  {
    free(c);
    c = tmp;
    tmp=tmp->next;
  }
  
  free(c);
  write(1,"free\n",5);
  return images;
}
