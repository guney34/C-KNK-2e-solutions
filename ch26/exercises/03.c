int int_str_printf(const char *const format, ...)
{
    va_list ap;
    va_start(ap, format);
    int n = 0;
    
    for (const char *ch = format; *ch; ++ch) {
        if (*ch != '%') {
            putchar(*ch);
            continue;
        }
        
        ++ch;
        if (*ch == 'd') {
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
        } else if (*ch == 's') {
            char *str = va_arg(ap, char *);

            while (*str)
                putchar(*str++);
            ++n;
        }
    }
    
    va_end(ap);
    return n;
}