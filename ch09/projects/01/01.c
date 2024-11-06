#include <stdio.h>

void selection_sort(int a[], int n)
{
    if (n < 1) 
        return;

    int max = 0;
    for (int i = 1; i < n; ++i) 
        if (a[i] > a[max]) 
            max = i;

    int temp = a[n-1];
    a[n-1] = a[max];
    a[max] = temp;

    selection_sort(a, n-1);
}

int main(void)
{
    int A[10] = {0};
    printf("Enter a series of 10 integers: ");

    for (int i = 0; i < 10; ++i)
        scanf("%d", &A[i]);
    
    printf("Sorted: ");
    selection_sort(A, 10);

    for (int i = 0; i < 10; ++i)
        printf("%d ", A[i]);
}