//a
int arr_largest(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; ++i)
        if (a[i] > max)
            max = a[i];
    return max;
}
//b
float arr_avg(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += a[i];
    return (float)sum / (float)n;
}
//c
int arr_num_pos(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] > 0)
            ++count;
    return count;
}