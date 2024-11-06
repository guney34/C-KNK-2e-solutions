#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

void generate_random_walk(char walk[10][10])
{
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            walk[row][col] = '.';
        }
    }

    walk[0][0] = 'A';
    char turn = 'A';
    int pos_r = 0;
    int pos_c = 0;

    srand((unsigned int)time(NULL));

    while (1) {
        turn += 1;
        int blocked[4] = {0};

        if (pos_r - 1 < 0 || walk[pos_r-1][pos_c] != '.')
            blocked[NORTH] = 1;
        if (pos_r + 1 >= ROWS || walk[pos_r+1][pos_c] != '.')
            blocked[SOUTH] = 1;
        if (pos_c - 1 < 0 || walk[pos_r][pos_c-1] != '.')
            blocked[WEST] = 1;
        if (pos_c + 1 >= COLS || walk[pos_r][pos_c+1] != '.')
            blocked[EAST] = 1;

        int num_blocked = blocked[NORTH] + blocked[EAST] + blocked[SOUTH] + blocked [WEST];
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
            case NORTH: walk[pos_r-1][pos_c] = turn; pos_r -= 1; break;
            case EAST:  walk[pos_r][pos_c+1] = turn; pos_c += 1; break;
            case SOUTH: walk[pos_r+1][pos_c] = turn; pos_r += 1; break;
            case WEST:  walk[pos_r][pos_c-1] = turn; pos_c -= 1; break;
        }
        if (turn == 'Z') 
            break;
    }
}

void print_array(char walk[10][10])
{
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            putchar(walk[row][col]);
            putchar(' ');
        }
        putchar('\n');
    }
}

int main(void)
{
    char A[ROWS][COLS] = {0};
    generate_random_walk(A);
    print_array(A);
}