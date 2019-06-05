#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../SDL/pixel_operations.h"

void take_samples(SDL_Surface *img, size_t x, size_t y, int samples[], int *nbsamples);
