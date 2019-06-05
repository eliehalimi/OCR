# include <stdio.h>
# include <stdlib.h>
# include "struct.h"


int main()
{
  struct edge *e = malloc(sizeof(struct edge));
  init_edge(e);
  printf("hello: %d\n",(e->g1));
  struct edge *f = malloc(sizeof(struct edge));
  init_edge(f);
  add_edge(e,12,13);
  printf("2: %d\n",(e->next->g1));
  add_edge(e,15,16);
  printf("3: %d\n",(e->next->next->g1));
  f = search_edge(e,13,12);
  printf("2: %d\n",(f->g1));
  printf("point: %ld\n", (e->next->point->x));
  add_point(e,1,2,13,12);
  printf("point: %ld\n",(e->next->point->next->x));
}
