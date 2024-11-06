#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int roll_dice(void)
{
    return 2 + rand() % 6 + rand() % 6;
}

bool play_game(void)
{
    int roll = roll_dice();
    printf("You rolled: %d\n", roll);

    switch (roll) {
        case 7: case 11:
            return true;
        case 2: case 3: case 12:
            return false;
        default:
            break;
    }
    
    int point = roll;
    printf("Your point is: %d\n", point);

    for(;;) {
        roll = roll_dice();
        printf("You rolled: %d\n", roll);

        if (roll == 7)
            return false;
        if (roll == point)
            return true;
    }
}

int main(void)
{
    srand((unsigned)time(NULL));
    int wins = 0;
    int losses = 0;
    
    for (;;) {
        if (play_game()) {
            printf("You win!\n\n");
            ++wins;
        } else {
            printf("You lose!\n\n");
            ++losses;
        }

        printf("Play again? ");

        prompt:
        char ch = (char)getchar();
        if (ch == 'y') {
            printf("\n");
            continue;
        }
        if (ch == 'n')
            break;
        else
            goto prompt;
    }
    printf("\nWins: %d Losses: %d", wins, losses);
}