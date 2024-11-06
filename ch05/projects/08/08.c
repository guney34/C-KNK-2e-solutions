#include <stdio.h>

int main(void)
{
    int h, m, time;

    int d1 = 8*60;
    int d2 = 9*60 + 43;
    int d3 = 11*60 + 19;
    int d4 = 12*60 + 47;
    int d5 = 14*60;
    int d6 = 15*60 + 45;
    int d7 = 19*60;
    int d8 = 21*60 + 45;

    printf("Enter a 24-hour time: ");
    scanf("%2d :%2d", &h, &m);
    time = 60*h + m;

    printf("Closest departure time is ");

    if      (time <= d1 + (d2 - d1) / 2) printf("8:00 a.m., arriving at 10:16 a.m.");
    else if (time <= d2 + (d3 - d2) / 2) printf("9:43 a.m., arriving at 11:52 a.m.");
    else if (time <= d3 + (d4 - d3) / 2) printf("11:19 a.m., arriving at 1:31 p.m.");
    else if (time <= d4 + (d5 - d4) / 2) printf("12:47 p.m., arriving at 3:00 p.m.");
    else if (time <= d5 + (d6 - d5) / 2) printf("2:00 p.m., arriving at 4:08 p.m.");
    else if (time <= d6 + (d7 - d6) / 2) printf("3:40 p.m., arriving at 5:55 p.m.");
    else if (time <= d7 + (d8 - d7) / 2) printf("7:00 p.m., arriving at 9:20 p.m.");
    else                                 printf("9:45 p.m., arriving at 11:58 p.m.");
}