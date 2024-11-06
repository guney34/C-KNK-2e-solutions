void *my_malloc(size_t size)
{
    void *p = malloc(size);
    if (p == NULL) {
        printf("Error, malloc failed\n");
        exit(EXIT_FAILURE);
    }
    return p;
}