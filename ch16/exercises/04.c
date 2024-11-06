// a)
typedef struct {double real, imaginary;} complex;

// b)
struct complex c1, c2, c3;

// c)
complex make_complex(const double real, const double imaginary)
{
    return (complex) {real, imaginary};
}

// d)
complex add_complex(const complex *c1, const complex *c2)
{
    return (complex) {c1->real + c2->real, c1->imaginary + c2->imaginary};
}