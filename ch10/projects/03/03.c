#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define RANK 0
#define SUIT 1
#define NUM_CARDS 5
#define NUM_SUITS 4
#define NUM_RANKS 13

int hand[NUM_CARDS][2];
bool straight, flush, four, three;
int pairs;

void read_cards();
void analyze_hand();
void print_result();

int main(void)
{
    for (;;) {
        read_cards();
        analyze_hand();
        print_result();
    }
}

void read_cards()
{
    char ch, rank_ch, suit_ch;
    int rank, suit;
    bool bad_card;
    int cards_read = 0;

    for (int i = 0; i < NUM_SUITS; ++i) {
        for (int card = 0; card < NUM_CARDS; ++card)
            hand[card][i] = 0;
    }

    while (cards_read < NUM_CARDS) {
        bad_card = false;

        printf("Enter a card: ");

        rank_ch = (char)getchar();
        switch (rank_ch) {
            case '0':           exit(EXIT_SUCCESS);
            case '2':           rank = 0; break;
            case '3':           rank = 1; break;
            case '4':           rank = 2; break;
            case '5':           rank = 3; break;
            case '6':           rank = 4; break;
            case '7':           rank = 5; break;
            case '8':           rank = 6; break;
            case '9':           rank = 7; break;
            case 't': case 'T': rank = 8; break;
            case 'j': case 'J': rank = 9; break;
            case 'q': case 'Q': rank = 10; break;
            case 'k': case 'K': rank = 11; break;
            case 'a': case 'A': rank = 12; break;
            default:            bad_card = true;
        }

        suit_ch = (char)getchar();
        switch (suit_ch) {
            case 'c': case 'C': suit = 0; break;
            case 'd': case 'D': suit = 1; break;
            case 'h': case 'H': suit = 2; break;
            case 's': case 'S': suit = 3; break;
            default:            bad_card = true;
        }

        while ((ch = (char)getchar()) != '\n')
            if (ch != ' ')
                bad_card = true;
 
        if (bad_card) {
            printf("Bad card; ignored.\n");
            continue;
        }

        bool duplicate = false;
        for (int i = 0; i < NUM_CARDS; ++i) {
            if (hand[i][RANK] == rank && hand[i][SUIT] == suit) {
                printf("Duplicate card; ignored.\n");
                duplicate = true;
                break;
            }
        }
        
        if (!duplicate) {
            hand[cards_read][RANK] = rank;
            hand[cards_read][SUIT] = suit;
            ++cards_read;
        }
    }
}

void analyze_hand()
{
    straight = false;
    flush = true;
    four = false;
    three = false;
    pairs = 0;

    for (int card = 1; card < NUM_CARDS; ++card) {
        if (hand[card][SUIT] != hand[0][SUIT]) {
            flush = false;
            break;
        }
    }
    
    for (int rank = 0; rank < NUM_RANKS; ++rank) {
        int same_rank = 0;
        for (int card = 0; card < NUM_CARDS; ++card) {
            if (hand[card][RANK] == rank)
                ++same_rank;
        }
        
        if (same_rank == 4) four = true;
        if (same_rank == 3) three = true;
        if (same_rank == 2) pairs++;
    }

    if (!four && !three && !pairs) {
        int rank_min = hand[0][RANK];
        int rank_max = hand[0][RANK];
        int rank_sum = hand[0][RANK];

        for (int card = 1; card < NUM_CARDS; ++card) {
            if (hand[card][RANK] > rank_max)
                rank_max = hand[card][RANK];
            if (hand[card][RANK] < rank_min)
                rank_min = hand[card][RANK];
            rank_sum += hand[card][RANK];
        }

        if (2 * rank_sum == rank_max * (rank_max + 1) - rank_min * (rank_min - 1))
            straight = true;
    }
}

void print_result(void)
{
    if (straight && flush)        printf("Straight flush");
    else if (four)                printf("Four of a kind");
    else if (three && pairs == 1) printf("Full house");
    else if (flush)               printf("Flush");
    else if (straight)            printf("Straight");
    else if (three)               printf("Three of a kind");
    else if (pairs == 2)          printf("Two pairs");
    else if (pairs == 1)          printf("Pair");
    else                          printf("High card");
    
    printf("\n\n");
}