#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int compare_ints(const void *p, const void *q)
{
    return (*(int *)p > *(int *)q) - (*(int *)p < *(int *)q);
}

int r_compare_ints(const void *p, const void *q)
{
    return (*(int *)p < *(int *)q) - (*(int *)p > *(int *)q);
}

int *create_rand_array(size_t num_elem)
{
    int *arr = malloc(num_elem * sizeof(int));
    if (arr == NULL) {
        perror("Malloc Error");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < num_elem; ++i)
        arr[i] = rand();

    return arr;
}

void time_qsort(size_t num_elem)
{
    int *arr = create_rand_array(num_elem);
    qsort(arr, num_elem, sizeof(int), r_compare_ints);

    
    clock_t t1 = clock();
    qsort(arr, num_elem, sizeof(int), compare_ints);
    clock_t t2 = clock();
    printf("Number of elements: %6zu, Time taken: %f seconds\n",
            num_elem, (t2-t1)/(double)CLOCKS_PER_SEC);

}

int main(void)
{
    srand(time(NULL));
    time_qsort(1000);
    time_qsort(10000);
    time_qsort(100000);
}