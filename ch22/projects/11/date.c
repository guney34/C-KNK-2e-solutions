#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    static char* months[] = {"January", "February", "March", "April", "May", "June", "July",
                             "August", "September", "October","November", "December"};

    if (argc != 2) {
        printf("usage: %s dd-mm-yyyy\nor: %s dd/mm/yyyy\n", argv[0], argv[0]);
        exit(EXIT_FAILURE);
    }

    int day, month, year;
    if (sscanf(argv[1], "%d%*[-/]%d%*[-/]%d%*[-/]", &day, &month, &year) != 3) {
        printf("Incorrect format entered\n");
        exit(EXIT_FAILURE);
    }
    printf("%s %d, %d\n", months[month-1], day, year);
}