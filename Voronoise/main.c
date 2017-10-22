#include <stdio.h>
#include <stdlib.h>
#include "dynarray.h"

int main()
{
    List l;
    init_l(&l, 5);
    for (int i = 0; i < 10; i++)
    {
        insert_l(&l, i);
    }
    for (int i = 0; i < l.size; i++)
    {
        printf("%d\n", l.list[i]);
    }
    printf("%d\n", search_l(&l, 5));
    printf("%d\n", search_l(&l, 12));
    printf("%d\n", search_l_coords(&l, 3, 4));
    printf("%d\n", search_l_coords(&l, 1, 6));
    return 0;
}
