// a)
int gcd(int m, int n)
{
    int remainder;
    while (n > 0) {
        remainder = m % n;
        m = n;
        n = remainder;
    }
    return m;
}

void reduce_frac(struct fraction *f)
{
    int n = gcd(abs(f->numerator), f->denominator);
    f->numerator /= n;
    f->denominator /= n;
}

// b)
struct fraction add_frac(const struct fraction *f1, const struct fraction *f2)
{
    struct fraction f3;
    f3.numerator = f1->numerator * f2->denominator + f2->numerator * f1->denominator;
    f3.denominator = f1->denominator * f2->denominator;
    reduce_frac(&f3);
    return f3;
}

// c)
struct fraction sub_frac(const struct fraction *f1, const struct fraction *f2)
{
    struct fraction f3;
    f3.numerator = f1->numerator * f2->denominator - f2->numerator * f1->denominator;
    f3.denominator = f1->denominator * f2->denominator;
    reduce_frac(&f3);
    return f3;
}

// d)
struct fraction mul_frac(const struct fraction *f1, const struct fraction *f2)
{
    struct fraction f3;
    f3.numerator = f1->numerator * f2->numerator;
    f3.denominator = f1->denominator * f2->denominator;
    reduce_frac(&f3);
    return f3;
}

// e)
struct fraction div_frac(const struct fraction *f1, const struct fraction *f2)
{
    struct fraction f3;
    f3.numerator = f1->numerator * f2->denominator;
    f3.denominator = f1->denominator * f2->numerator;
    reduce_frac(&f3);
    return f3;
}