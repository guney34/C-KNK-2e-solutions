int int_printf(const char *const format, ...)
{
    va_list ap;
    va_start(ap, format);
    int n = 0;
    
    for (const char *ch = format; *ch; ++ch) {
        if (*ch != '%') {
            putchar(*ch);
            continue;
        }

        if (*(++ch) != 'd')
            continue;
        
        int num = va_arg(ap, int);

        if (num < 0) {
            putchar('-');
            num = -num;
        }

        int num_r = 0;

        while(num != 0) {
            int r = num % 10;
            num_r = num_r*10 + r;
            num /= 10;
        }

        do {
            putchar(num_r%10 + '0');
            num_r /= 10;
        } while (num_r);

        ++n;
    }
    
    va_end(ap);
    return n;
}