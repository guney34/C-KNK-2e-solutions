#include <stdio.h>
#include <stddef.h>

struct s {
    char a;
    int b[2];
    float c;
};

int main(void)
{
    printf("Size of s: %zu\n", sizeof(struct s));
    printf("Size of a: %zu\n", sizeof(((struct s){}).a));
    printf("Size of b: %zu\n", sizeof(((struct s){}).b));
    printf("Size of c: %zu\n", sizeof(((struct s){}).c));

    printf("Offset of a: %zu\n", offsetof(struct s, a));
    printf("Offset of b: %zu\n", offsetof(struct s, b));
    printf("Offset of c: %zu\n", offsetof(struct s, c));

    /*
    Output:
    Size of s: 16
    Size of a: 1
    Size of b: 8
    Size of c: 4
    Offset of a: 0
    Offset of b: 4
    Offset of c: 12

    struct s has 3 bytes of padding between a and b
    */
    
}