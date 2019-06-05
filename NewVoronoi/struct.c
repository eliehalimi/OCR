# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include <assert.h>
# include <err.h>
# include <stdio.h>
# include <stdlib.h>
# include "../SDL/pixel_operations.h"
# include "struct.h"

void init_point(struct point *p)
{
  p->next = NULL;
  p->prev = NULL;
  p->x = -1;
  p->y = -1;
}

void init_edge(struct edge *e)
{
  e->next = NULL;
  e->prev = NULL;
  e->g1 = 0;
  e->g2 = 0;
  e->point = malloc(sizeof(struct point));
  init_point(e->point);
}

void del_edge(struct edge *e, int g1, int g2)
{
  struct edge *tmp = e;
  while ((tmp->g1 != g1 || tmp->g2 != g2) && (tmp->g1 != g2 || tmp->g2 != g1))
    {
      tmp = tmp->next;
    }
  tmp->prev->next = tmp->next;
}

void add_point(struct edge *e, size_t x, size_t y, int g1, int g2)
{
  struct edge *tmp = e;
  while ((tmp->next != NULL) && ((tmp->g1 != g1 || tmp->g2 != g2) && (tmp->g1 != g2 || tmp->g2 != g1)))
    {
      tmp = tmp->next;
    }
  if (tmp->next == NULL)
    {
      add_edge(tmp, g1, g2);
      tmp = tmp->next;
    }
  struct point *tmp2 = tmp->point;
  while (tmp2->next != NULL)
    {
      tmp2 = tmp2->next;
    }
  tmp2->next = malloc(sizeof(struct point));
  tmp2->next->prev = tmp2;
  tmp2->next->x = x;
  tmp2->next->y = y;
}

void add_edge(struct edge *e,int g1, int g2)
{
  struct edge *tmp = e;
  while (tmp->next != NULL)
    {
      tmp = tmp->next;
    }
  tmp->next = malloc(sizeof(struct edge));
  tmp->next->prev = tmp;
  tmp->next->g1 = g1;
  tmp->next->g2 = g2;
  tmp->next->point = malloc(sizeof(struct point));
  init_point(tmp->next->point);
}

int exist_edge(struct edge *e, int g1,int g2)
{
  if (e->g1 == g1 && e->g2 == g2)
    {
      return 1;
    }
  while (e->next != NULL)
    {
      e = e->next;
      if ((e->g1 == g1 && e->g2 == g2) ||(e->g1 == g2 && e->g2 == g1))
	{
	  return 1;
	}
    }
  return 0;
}

struct edge* search_edge(struct edge *e, int g1,int g2)
{
  if (e->g1 == g1 && e->g2 == g2)
    {
      return e;
    }
  while (e->next != NULL)
    {
      e = e->next;
      if ((e->g1 == g1 && e->g2 == g2) ||(e->g1 == g2 && e->g2 == g1))
        {
          return e;
        }
    }
  return NULL;
}


