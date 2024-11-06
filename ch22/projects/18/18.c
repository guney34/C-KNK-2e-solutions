#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUM 10000

int compare_ints(const void *p, const void *q)
{
    return (*(int *)p > *(int *)q) - (*(int *)p < *(int *)q);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    
    int nums[MAX_NUM];
    size_t count = 0;

    while (fscanf(fp, "%d", nums + count) == 1) {
        ++count;
        if (count >= MAX_NUM)
            break;
    }

    qsort(nums, count, sizeof(int), compare_ints);

    printf("Largest number: %d\n", nums[count-1]);
    printf("Smallest number: %d\n", nums[0]);
    printf("Median number: %d\n", count%2 ? nums[count/2] : (nums[count/2]+nums[count/2 - 1])/2);

    fclose(fp);
}
