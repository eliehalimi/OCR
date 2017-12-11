#include <stdlib.h>
#include <stdio.h>
#include "dynarray.h"

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

int search_l(List *l, int e)
{
    for (size_t i = 0; i < l -> size - 1; i++)
    {
        if (l -> list[i] == e)
        {
            return 1;
        }
    }
    return 0;
}

int search_l_coords(List *l, int x, int y)
{
    for (size_t i = 0; i < l -> size - 2; i++)
    {
        if (l -> list[i] == x && l -> list[i + 1] == y)
        {
            return 1;
        }
    }
    return 0;
}
