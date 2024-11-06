char *max_pair(int num_pairs, ...)
{
    va_list ap;
    va_start(ap, num_pairs);

    int largest = va_arg(ap, int);
    char *str = va_arg(ap, char *);

    while (--num_pairs) {
        int temp = va_arg(ap, int);
        if (temp > largest) {
            largest = temp;
            str = va_arg(ap, char *);
        } else
            va_arg(ap, char *);
    }

    va_end(ap);
    return str;
}