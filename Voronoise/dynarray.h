typedef struct 
{
    int *list;
    size_t used;
    size_t size;
} 
List;

void init_l(List *l, size_t initSize) 
{
    l->list = (int *)malloc(initSize * sizeof(int));
    l->used = 0;
    l->size = initSize;
}

void insert_l(List *l, int e)
{
    if (l->used == l->size) 
    {
        l->size *= 2;
        l->list = (int *)realloc(l->list, l->size * sizeof(int));
    }
    l->list[l->used++] = e;
}

void free_l(List *l) 
{
    free(l->list);
    l->list = NULL;
    l->used = l->size = 0;
}
