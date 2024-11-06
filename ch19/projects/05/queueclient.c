#include <stdio.h>
#include "queueADT.h"

int main(void)
{
    Queue s1, s2;
    int n;

    s1 = queue_create();
    s2 = queue_create();

    queue_insert(s1, 1);
    queue_insert(s1, 2);

    n = queue_remove(s1);
    printf("Removed %d from s1\n", n);
    queue_insert(s2, n);
    n = queue_remove(s1);
    printf("Removed %d from s1\n", n);
    queue_insert(s2, n);

    queue_destroy(s1);

    while (!queue_is_empty(s2))
        printf("Removed %d from s2\n", queue_remove(s2));

    queue_insert(s2, 3);
    queue_make_empty(s2);
    if (queue_is_empty(s2))
        printf("s2 is empty\n");
    else
        printf("s2 is not empty\n");

    queue_destroy(s2);
}
