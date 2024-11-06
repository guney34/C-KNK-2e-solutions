#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LEN 256

struct time {
    int hr, min;
};

struct flight {
    struct time dep, arr;
};

int main(void)
{
	FILE *fp = fopen("flights.dat", "rb");
    if (fp == NULL) {
        printf("Error: Failed to open %s\n", "flights.dat");
        exit(EXIT_FAILURE);
    }

    int h, m;
    printf("Enter a 24-hour time: ");
    scanf("%2d :%2d", &h, &m);
    int time = 60*h + m;

    char line_str[MAX_LINE_LEN+1];
    struct flight flight, closest_flight;
    int diff = INT_MAX;

    while (fgets(line_str, sizeof(line_str), fp) != NULL) {
		sscanf(line_str, "%d:%d %d:%d", &flight.dep.hr, &flight.dep.min, &flight.arr.hr, &flight.arr.min);
        if (diff > abs(time - (flight.dep.hr * 60 + flight.dep.min))) {
            closest_flight = flight;
            diff = abs(time - (flight.dep.hr * 60 + flight.dep.min));
        }
	}

    fclose(fp);

    if (diff == INT_MAX) {
        printf("flights.dat is empty\n");
        exit(EXIT_FAILURE);
    }

    printf("Closest departure time is %.2d:%.2d, arriving at %.2d:%.2d\n",
        closest_flight.dep.hr, closest_flight.dep.min, closest_flight.arr.hr, closest_flight.arr.min);

}