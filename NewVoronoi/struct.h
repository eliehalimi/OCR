struct point
{
  struct point *next,*prev;
  size_t x,y;
};

struct edge
{
  struct edge *next,*prev;
  int g1,g2;
  struct point *point;
};

void init_point(struct point *p);

void init_edge(struct edge *e);

void del_edge(struct edge *e, int g1, int g2);

void add_point(struct edge *e, size_t x, size_t y, int g1, int g2);

void add_edge(struct edge *e,int g1, int g2);

struct edge* search_edge(struct edge *e, int g1,int g2);







