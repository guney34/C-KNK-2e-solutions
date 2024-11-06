#include <stdio.h>

struct flight {
    int dep;
    int arr;
};

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
    static const struct flight times[] = {{480, 616}, {583, 712}, {679, 811}, {767, 900},
                                          {840, 968}, {945, 1075}, {1140, 1280}, {1305, 1438}};
    for (int i = 0; i < 8; ++i) {
        if (i == 7 || desired_time <= times[i].dep + (times[i + 1].dep - times[i].dep) / 2) {
            *departure_time = times[i].dep;
            *arrival_time = times[i].arr;
            break;
        }
    }
}