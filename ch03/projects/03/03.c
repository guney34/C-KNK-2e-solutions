#include <stdio.h>

int main()
{
    int GS1, group, publisher, item, check;

    printf("Enter ISBN: ");
    scanf("%d -%d -%d -%d -%d", &GS1, &group, &publisher, &item, &check);

    printf("GS1 prefix: %d\n", GS1);
    printf("Group identifier: %d\n", group);
    printf("Publisher code: %d\n", publisher);
    printf("Item number: %d\n", item);
    printf("Check digit: %d\n", check);
}