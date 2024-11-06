#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50 
#define MSG_LEN 60 

int read_line(char str[], int n);

int main(void)
{
    char reminders[MAX_REMIND][MSG_LEN+3];
    char date_time_str[16], msg_str[MSG_LEN+1];
    int month, day, hr, min, i, j, num_remind = 0;
    
    for (;;) {

        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }
    
        printf("Enter 'mm/dd hh/mm reminder': ");

        scanf("%d", &month);
        if (month == 0)
            break;
        if (month < 0 || month > 12) {
            printf("Error, invalid month\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        scanf(" /%d", &day);
        if (day <= 0 || day > 31) {
            printf("Error, invalid day\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        scanf("%d :%d", &hr, &min);
        if (hr > 23 || hr < 0 || min > 59 || min < 0) {
            printf("Error, invalid time");
            while (getchar() != '\n')
                ;
            continue;
        }

        sprintf(date_time_str, "%5d %3d %2d:%2.2d", month, day, hr, min);
        read_line(msg_str, MSG_LEN);

        for (i = 0; i < num_remind; i++)
            if (strcmp(date_time_str, reminders[i]) < 0)
                break;
        for (j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j-1]);

        strcpy(reminders[i], date_time_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    printf("\nMonth Day  Time Reminder\n");
    for (i = 0; i < num_remind; i++)
        printf("%s\n", reminders[i]);
}

int read_line(char str[], int n)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}