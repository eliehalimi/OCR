#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "../SDL/pixel_operations.h"
#include "dynarray.h"

void is_connected(SDL_Surface *img, size_t x, size_t y, size_t i, size_t j, List l);

void deledge(SDL_Surface *img, size_t x, size_t y, int samples[], int lines[]);
