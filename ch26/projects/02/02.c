#include <stdio.h>
#include <stdlib.h>

void f1(void)
{
    printf("That's all,");
}

void f2(void)
{
    printf(" folks.");
}

int main(void)
{
    atexit(f2);
    atexit(f1);
}