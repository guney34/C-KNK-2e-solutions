int line_length(const char *filename, int n)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
        return 0;

    for (int i = 1; i < n; ++i)
        fscanf(file, "%*[^\n]%*c");

    int count = 0;
    int ch = fgetc(file);
    while (ch != '\n' && ch != EOF) {
        ++count;
        ch = fgetc(file);
    }
    
    fclose(file);
    return count;
}