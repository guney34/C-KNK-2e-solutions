for (int *p = temperatures[0]; p < temperatures[7]; p += 24)
    printf("%d ", *find_largest(p, 24));