#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../SDL/pixel_operations.h"

int Root(size_t k, int label[],size_t x,size_t y);

void SetEquivalent(size_t i,size_t k, int label[], size_t x,size_t y);

void labels(SDL_Surface *img, size_t x,size_t y, int label[], int samples[], int *nbsamples, int components[], int *nbcomponents);
