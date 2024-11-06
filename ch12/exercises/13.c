#define N 10

double ident[N][N] = {0};

for (double *p = &ident[0][0]; p < &ident[N][N]; p += N + 1)
   *p = 1;