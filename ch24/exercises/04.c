//a)
double try_math_fcn(double (*fptr)(double), double x, char *err_msg)
{
    errno = 0;
    double result = fptr(x);
    if (errno) {
        perror(err_msg);
        exit(EXIT_FAILURE);
    }
    return result;
}

//b)
#define TRY_MATH_FCN(fptr, x) try_math_fcn((fptr), (x), "Error in call of "#fptr)