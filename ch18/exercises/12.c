int (*f(float (*)(long), char *))(double);

/* a)
f is a function with two arguments:
    1. a pointer to a function with one long argument that returns a float
    2. a pointer to a char variable
f returns a pointer to a function with one double argument and returns an int
*/

//b)
int (*fcn_ptr)(double) = f(some_func, &char_var);
int result = fcn_ptr(double_var);

// or in one line:
int result = (*f(some_func, &char_var))(double_var);