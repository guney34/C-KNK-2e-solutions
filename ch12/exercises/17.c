int sum_two_dimensional_array(const int a[][24], int n)
{
    int sum = 0;
    for (const int *p = *a; p < *a + n*24; ++p)
        sum += *p;
    return sum;
}