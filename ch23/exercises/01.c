double round_nearest(double x, int n)
{
    double power = pow(10, n);

    return (x < 0.0 ? ceil(x*power - 0.5) : floor(x*power + 0.5))/power;
}