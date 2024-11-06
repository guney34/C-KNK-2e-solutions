#include <stdio.h>
#include <math.h>

void create_magic_square(int n, char magic_square[n][n])
{
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            magic_square[row][col] = 0;
        }
    }

    magic_square[0][n / 2] = 1;
    int r = 0;
    int c = n / 2;
    int next_r, next_c;

    for (int i = 1; i < n*n; ++i) {
        next_r = r - 1;
        if (next_r == -1) 
            next_r = n - 1;
        next_c = (c + 1) % n;

        if (magic_square[next_r][next_c]) {
            next_r = (r + 1) % n;
            next_c = c;
        }
        magic_square[next_r][next_c] = i + 1;
        r = next_r;
        c = next_c;
    }
}

void print_magic_square(int n, char magic_square[n][n])
{
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            printf("\t%d", magic_square[row][col]);
        }
        putchar('\n');
    }
}

int main(void)
{
    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");

    int size;
    scanf("%d", &size);
    char A[size][size];

    create_magic_square(size, A);
    print_magic_square(size, A);
}