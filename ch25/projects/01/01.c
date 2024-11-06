#include <stdio.h>
#include <locale.h>
#include <string.h>

int main(void)
{
    char *c = setlocale(LC_ALL, NULL);

    char *native = setlocale(LC_ALL, "");

    printf("Native locale and C locale are %s the same\n", strcmp(c, native) ? "not" : "");
}