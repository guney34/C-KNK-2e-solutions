// a)
struct complex {double real, imaginary;};

// b)
struct complex c1, c2, c3;

// c)
struct complex make_complex(const double real, const double imaginary)
{
    return (struct complex) {real, imaginary};
}

// d)
struct complex add_complex(const struct complex *c1, const struct complex *c2)
{
    return (struct complex) {c1->real + c2->real, c1->imaginary + c2->imaginary};
}