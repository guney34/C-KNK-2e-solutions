void display(int n, ...)
{
    va_list ap;
    va_start(ap, n);

    while (n--) {
        char *str = va_arg(ap, char *);
        
        while (*str)
            putchar(*str++);

        if (n)
            putchar(' ');
    }
    putchar('\n');

    va_end(ap);
}