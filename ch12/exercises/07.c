bool search(const int a[], int n, int key)
{
    for (const int *p = a; p < a + n; ++p)
        if (*p == key)
            return true;
    return false;
}