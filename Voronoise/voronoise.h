#ifndef VORONOISE_H_
#define VORONOISE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
#include "../SDL/pixel_operations.h"


int take_samples(SDL_Surface *img, size_t x, size_t y, int samples[]);

#endif
