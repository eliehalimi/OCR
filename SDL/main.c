// main.c

# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include <assert.h>
# include <err.h>
# include <stdio.h>
# include <stdlib.h>
# include "pixel_operations.h"
# include <unistd.h>
/*
# include "../NewVoronoi/struct.h"
# include "../NewVoronoi/Bruteforce.h"
# include "../NewVoronoi/label.h"
# include "../NewVoronoi/voronoi.h"
*/
#include "../NoNeed4Voronoi/label.h"

void print_matrix(int mat[], size_t lines, size_t cols);


void wait_for_keypressed(void) {
  SDL_Event             event;
  // Infinite loop, waiting for event
  for (;;) {
    // Take an event
    SDL_PollEvent( &event );
    // Switch on event type
    switch (event.type) {
    // Someone pressed a key -> leave the function
    case SDL_KEYDOWN: return;
    default: break;
    }
  // Loop until we got the expected event
  }
}


void init_sdl(void) {
  // Init only the video part
  if( SDL_Init(SDL_INIT_VIDEO)==-1 ) {
    // If it fails, die with an error message
    errx(1,"Could not initialize SDL: %s.\n", SDL_GetError());
  }
  // We don't really need a function for that ...
}


SDL_Surface* load_image(char *path) {
  SDL_Surface          *img;
  // Load an image using SDL_image with format detection
  img = IMG_Load(path);
  if (!img)
    // If it fails, die with an error message
    errx(3, "can't load %s: %s", path, IMG_GetError());
  return img;
}




SDL_Surface* display_image(SDL_Surface *img)
{
  SDL_Surface          *screen;
  // Set the window to the same size as the image
  screen = SDL_SetVideoMode(img->w, img->h, 0, SDL_SWSURFACE|SDL_ANYFORMAT);
  if ( screen == NULL ) {
    // error management
    errx(1, "Couldn't set %dx%d video mode: %s\n",
         img->w, img->h, SDL_GetError());
  }

  /* Blit onto the screen surface */
  if(SDL_BlitSurface(img, NULL, screen, NULL) < 0)
    warnx("BlitSurface error: %s\n", SDL_GetError());

  // Update the screen
  SDL_UpdateRect(screen, 0, 0, img->w, img->h);


  // wait for a key
  wait_for_keypressed();

  // return the screen for further uses
  return screen;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
		return -1;
	SDL_Surface* img = load_image(argv[1]);
	Uint8 r,g,b;
	for (int i = 0; i < img->w; i++)
	{
		for (int j = 0; j < img->h; j++)
		{
			Uint32 pixel = getpixel(img, i, j);
			SDL_GetRGB(pixel, img -> format, &r, &g, &b);
			float luminance = (r*0.3 +g*0.59 +b*0.11);

			if (luminance < 128)
				luminance = 0;
			else
			{
				luminance = 255;
			}

			pixel = SDL_MapRGB(img->format, luminance, luminance, luminance);
			putpixel(img, i, j, pixel);
		}
	}
	write(1,"COUCOU\n",7);
	display_image(img);
	size_t x = img->w;
	size_t y = img->h;
	/*
	int samples[x * y];
	for (size_t i = 0; i < x * y; i++)
	{
		samples[i] = -1;
	}
	
	int nbsamples = 0;

	int lines[x*y];
	
        for (size_t i = 0; i < x * y; i++)
        {                                                                                                                     
          lines[i] = -1;
        }
	*/
	int label[x*y];
	/*
	int components[x*y];
	int nbcomponents = 0;
	*/
	struct images *images = labels(img, x, y, label);
	/*
	struct edge *e = malloc(sizeof(struct edge));
	init_edge(e);
	printf("init\n");
	labels(img, x, y, label, samples, &nbsamples, components, &nbcomponents);
	
	printf("Labeled\n");
	bruteforce(img, x, y, samples, nbsamples, lines, label, e);
	printf("Brute\n");
	merge(img, e);
	*/
	int *image = images->next->image;
	printf("%d",images->next->y);
	printf("%d", images->next->x);
	for (int j = 0; j < images->next->y; j++)
	  {
	    for (int i = 0; i<images->next->x; i++)
	      {
		printf("%d",*(image + i + j* x));
		fflush(stdout);
	      }
	    printf("\n");
	  }
}

