#ifndef DELEDGE_H_
#define DELEDGE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../SDL/pixel_operations.h"
#include "dynarray.h"

void white(SDL_Surface *img, size_t i, size_t j);

int is_connected(SDL_Surface *img, size_t x, size_t y, size_t i, size_t j, size_t i2, size_t j2, List *l);


void deledge(SDL_Surface *img, size_t x, size_t y, int lines[], int samples[]);

#endif
