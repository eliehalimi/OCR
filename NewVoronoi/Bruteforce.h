# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include <assert.h>
# include <err.h>
# include <stdio.h>
# include <stdlib.h>
# include "../SDL/pixel_operations.h"

int sq(int x, int y);

void bruteforce(SDL_Surface *img, size_t x, size_t y, int samples[], int nbsamples, int lines[], int label[], struct edge *e);


