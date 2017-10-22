# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include <assert.h>
# include <err.h>
# include <stdio.h>
# include <stdlib.h>
# include "../SDL/pixel_operations.h"

void green(SDL_Surface *img, size_t i, size_t j);

int sq(int x, int y);

void bruteforce(SDL_Surface *img, size_t x, size_t y, int samples[], int nbsamples, int lines[]);

void drawgreen(SDL_surface *img, size_t x, size_t y, int samples[], int nbsamples, int lines[]);


