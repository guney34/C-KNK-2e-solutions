#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3


int main(void)
{
    char A[ROWS][COLS] = {0};
    int pos_r = 0;
    int pos_c = 0;

    A[0][0] = 'A';
    char turn = 'A';
    srand((unsigned int)time(NULL));

    while (1) {
        turn += 1;
        int blocked[4] = {0};

        if (pos_r - 1 < 0 || A[pos_r-1][pos_c])
            blocked[NORTH] = 1;
        if (pos_r + 1 >= ROWS || A[pos_r+1][pos_c])
            blocked[SOUTH] = 1;
        if (pos_c - 1 < 0 || A[pos_r][pos_c-1])
            blocked[WEST] = 1;
        if (pos_c + 1 >= COLS || A[pos_r][pos_c+1])
            blocked[EAST] = 1;

        int num_blocked = blocked[NORTH] + blocked[EAST] + blocked[SOUTH] + blocked[WEST];
        if (num_blocked == 4)
            break;
        
        int r = rand() % (4 - num_blocked);
        
        // convert r to direction
        int count = 0;
        int dir = -1;
        while (count != r+1) {
            ++dir;
            if(blocked[dir] == 0)
                ++count;
        }
        switch (dir) {
            case NORTH: A[pos_r-1][pos_c] = turn; pos_r -= 1; break;
            case EAST:  A[pos_r][pos_c+1] = turn; pos_c += 1; break;
            case SOUTH: A[pos_r+1][pos_c] = turn; pos_r += 1; break;
            case WEST:  A[pos_r][pos_c-1] = turn; pos_c -= 1; break;
        }
        if (turn == 'Z')
            break;
    }

    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            if (A[row][col] == 0)
                putchar('.');
            else
                putchar(A[row][col]);
            putchar(' ');
        }
        putchar('\n');
    }
}