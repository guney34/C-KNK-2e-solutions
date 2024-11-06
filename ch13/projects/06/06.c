#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 9

int str_equal(const char *str1, const char *str2)
{
    for (int i = 0; toupper(str1[i]) == toupper(str2[i]); ++i) {
        if (str1[i] == '\0')
            return 1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    char *planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};
    int i, j;

    for (i = 1; i < argc; i++) {
        for (j = 0; j < NUM_PLANETS; j++)
            if (str_equal(argv[i], planets[j])) {
                printf("%s is planet %d\n", argv[i], j + 1);
                break;
            }
        if (j == NUM_PLANETS)
            printf("%s is not a planet\n", argv[i]);
    }
}