#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"



int main(int argc, const char *argv[])
{
    DLink *head = dlist_create(-1);
    for (int i = 0;i < 10;i++)
        dlist_add_head(head, dlist_create(i));
    dlist_sort(head, 2);
    dlist_printf(head);
    dlist_sort(head, 1);
    dlist_printf(head);
    dlist_free(head);
    return 0;
}

