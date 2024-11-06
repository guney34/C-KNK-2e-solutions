double evaluate_polynomial(double a[], int n, double x)
{
    double result = a[n];
    while(n)
        result = fma(result, x, a[--n]);
    return result;
}