#include <stdio.h>

#define STUDENTS 5
#define QUIZES 5
#define MAX_SCORE 100

int main(void)
{
    int A[STUDENTS][QUIZES] = {0};
    int s_totals[STUDENTS] = {0};
    int q_totals[QUIZES] = {0};
    int high_score[QUIZES] = {0};
    
    int low_score[QUIZES];
    for (int q = 0; q < QUIZES; ++q)
        low_score[q] = MAX_SCORE;

    for (int s = 0; s < STUDENTS; ++s) {
        printf("Enter grades for student %d: ", s + 1);
        for (int q = 0; q < QUIZES; ++q) {
            scanf("%d", &A[s][q]);

            if(A[s][q] > high_score[q])
                high_score[q] = A[s][q];
                
            if(A[s][q] < low_score[q])
                low_score[q] = A[s][q];

            s_totals[s] += A[s][q];
            q_totals[q] += A[s][q];
        }
    }
    for (int s = 0; s < STUDENTS; ++s) {
        printf("\nStudent %d: Total Score: %d ", s + 1, s_totals[s]);
        printf(", Average Score: %.2f ", (float)s_totals[s] / (float)QUIZES);
    }
    for (int q = 0; q < QUIZES; ++q) {
        printf("\nQuiz %d: Average Score: %.2f ", q + 1, (float)q_totals[q] / (float)STUDENTS);
        printf(", High Score: %d ", high_score[q]);
        printf(", Low Score: %d ", low_score[q]);
    }
}