#include <stdio.h>

int main(void)
{
    int h, m, time;
    
    int d[8] = {480, 583, 679, 767, 840, 945, 1140, 1305};
    int a[8] = {616, 712, 811, 900, 968, 1075, 1280, 1438};

    printf("Enter a 24-hour time: ");
    scanf("%2d :%2d", &h, &m);
    time = 60*h + m;

    for (int i = 0; i < 8; ++i) {
        if (i == 7 || time <= d[i] + (d[i + 1] - d[i]) / 2) {
            printf("Closest departure time is %d:%.2d, arriving at %d:%.2d",
                   d[i] / 60, d[i] - 60 * (d[i] / 60),
                   a[i] / 60, a[i] - 60 * (a[i] / 60));
            break;
        }
    }
}