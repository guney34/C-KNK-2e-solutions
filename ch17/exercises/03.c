int *create_array(int n, int initial_value)
{
    int *arr = malloc(n * sizeof(int));
    if (arr == NULL)
        return NULL;
    for (int *p = arr; p < arr + n; ++p)
        *p = initial_value;
    return arr;
}