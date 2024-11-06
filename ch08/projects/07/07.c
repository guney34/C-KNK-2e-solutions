#include <stdio.h>

#define ROWS 5
#define COLUMNS 5

int main(void)
{
    int A[ROWS][COLUMNS] = {0};
    int row_totals[ROWS] = {0};
    int col_totals[COLUMNS] = {0};

    for (int row = 0; row < ROWS; ++row) {
        printf("Enter row %d: ", row + 1);
        for (int col = 0; col < COLUMNS; ++col) {
            scanf("%d", &A[row][col]);
            row_totals[row] += A[row][col];
            col_totals[col] += A[row][col];
        }
    }
    printf("\nRow totals: ");
    for (int row = 0; row < ROWS; ++row)
        printf("%d ", row_totals[row]);
        
    printf("\nCol totals: ");
    for (int col = 0; col < COLUMNS; ++col)
        printf("%d ", col_totals[col]);
}