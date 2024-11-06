double median(double x, double y, double z)
{
    double median;
    if (x <= y)
        if (y <= z)
            median = y;
        else if (x <= z)
            median = z;
        else
            median = x;
    if (z <= y)
        median = y;
    if (x <= z)
        median = x;
    median = z;
    return median;
}