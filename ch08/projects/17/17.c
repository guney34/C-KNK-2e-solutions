#include <stdio.h>
#include <math.h>

int main(void)
{
    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");

    int size;
    scanf("%d", &size);
    int A[size][size];

    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            A[row][col] = 0;
        }
    }

    A[0][size/2] = 1;

    int r = 0;
    int c = size / 2;
    int next_r, next_c;

    for (int i = 1; i < size*size; ++i) {
        next_r = r-1;
        if (next_r == -1) next_r = size-1;
        next_c = (c+1)%size;

        if (A[next_r][next_c]) {
            next_r = (r+1) % size;
            next_c = c;
        }
        A[next_r][next_c] = i+1;
        r = next_r;
        c = next_c;
    }

    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            printf("\t%d", A[row][col]);
        }
        putchar('\n');
    }
}