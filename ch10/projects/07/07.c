#include <stdio.h>

#define MAX_DIGITS 10

const int segments[10][7] = {{1, 1, 1, 1, 1, 1, 0},
                             {0, 1, 1, 0, 0, 0, 0},
                             {1, 1, 0, 1, 1, 0, 1},
                             {1, 1, 1, 1, 0, 0, 1},
                             {0, 1, 1, 0, 0, 1, 1},
                             {1, 0, 1, 1, 0, 1, 1},
                             {1, 0, 1, 1, 1, 1, 1},
                             {1, 1, 1, 0, 0, 0, 0},
                             {1, 1, 1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 0, 1, 1}};

char digits[4][MAX_DIGITS * 4];

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void)
{
    clear_digits_array();
    printf("Enter a number: ");

    char ch;
    int pos = 0;
    while((ch = (char)getchar()) != '\n') {
        if (ch > '9' || ch < '0' || pos > 4 * (MAX_DIGITS - 1))
            continue;

        process_digit((int)(ch - '0'), pos);
        pos += 4;
    }
    print_digits_array();
}

void clear_digits_array(void)
{
    for (int row = 0; row < 4; ++row)
        for (int col = 0; col < MAX_DIGITS * 4; ++col)
            digits[row][col] = ' ';
}

void process_digit(int digit, int position)
{
    for (int segment = 0; segment < 7; ++segment) {
        if (!segments[digit][segment])
            continue;

        switch (segment) {
            case 0: digits[0][position + 1] = '_'; break;
            case 1: digits[1][position + 2] = '|'; break;
            case 2: digits[2][position + 2] = '|'; break;
            case 3: digits[2][position + 1] = '_'; break;
            case 4: digits[2][position + 0] = '|'; break;
            case 5: digits[1][position + 0] = '|'; break;
            case 6: digits[1][position + 1] = '_'; break;
        }
    }
}

void print_digits_array(void)
{
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < MAX_DIGITS * 4; ++col)
            printf("%c", digits[row][col]);
        printf("\n");
    }
}