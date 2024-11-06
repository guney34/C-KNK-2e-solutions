#include <stdio.h>

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);

int main(void)
{
    int h, m, time, departure, arrival;

    printf("Enter a 24-hour time: ");
    scanf("%2d :%2d", &h, &m);
    time = 60*h + m;

    find_closest_flight(time, &departure, &arrival);

    printf("Closest departure time is %d:%.2d, arriving at %d:%.2d",
           departure / 60, departure - 60 * (departure / 60),
           arrival / 60, arrival - 60 * (arrival / 60));

}

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time)
{
    static int d[8] = { 480, 583, 679, 767, 840, 945, 1140, 1305 };
    static int a[8] = { 616, 712, 811, 900, 968, 1075, 1280, 1438 };

    for (int i = 0; i < 8; ++i) {
        if (i == 7 || desired_time <= d[i] + (d[i + 1] - d[i]) / 2) {
            *departure_time = d[i];
            *arrival_time = a[i];
            break;
        }
    }
    return;
}