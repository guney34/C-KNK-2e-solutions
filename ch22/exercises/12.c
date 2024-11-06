// the function reads two characters for each comparison, causing it to skip characters
// to fix it, store the value of fgetc

int count_periods(const char *filename)
{
    FILE *fp;
    int n = 0;
    int ch;

    if ((fp = fopen(filename, "r")) != NULL) {
        while ( (ch = fgetc(fp)) != EOF)
            if (ch == '.')
                n++;
        fclose(fp);
    }
    
    return n;
}