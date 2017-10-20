#ifndef VORONOISE_H_
#define VORONOISE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
#include "SDL/pixel_operations.h"
#include "SDL/pixel.operations.c"
#endif

int take_samples[][](SDL_Surface img, size_t x, size_t y);
