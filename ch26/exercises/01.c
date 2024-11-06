int max_int(int first, ...)
{
    va_list ap;
    int current, largest;

    va_start(ap, n);
    largest = first;

    while ((current = va_arg(ap, int)) != 0) {
        if (current > largest)
            largest = current;
    }
    va_end(ap);
    return largest;
}