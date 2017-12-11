#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../SDL/pixel_operations.h"

struct components
{
  struct components *next;
  size_t up,down,left,right;
};

struct images
{
  struct images *next;
  int *image;
  int x,y;
};

void add_comp(struct components *c, size_t x, size_t y);

void compare(struct components *c,size_t x, size_t y, int i);

void add_image(int label[], struct components *c, struct images *images);

int Root(size_t k, int label[],size_t x,size_t y);

void SetEquivalent(size_t i,size_t k, int label[], size_t x,size_t y);

struct images* labels(SDL_Surface *img, size_t x,size_t y, int label[]);
