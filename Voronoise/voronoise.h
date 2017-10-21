#ifndef VORONOISE_H_
#define VORONOISE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
#include "../SDL/pixel_operations.h"


void take_samples(SDL_Surface *img, size_t x, size_t y, int samples[], int *nbsamples);

void cut(int samples[], nbsamples, int left[], int nbleft, int right[], int nbright);

void divacon(SDL_Surface *img, size_t x, size_t y, int samples[], int nbsamples);

void __divacon(SDL_Surface *img, size_t x, size_t y, int left[], int right[], int nbleft, int nbright);

#endif
