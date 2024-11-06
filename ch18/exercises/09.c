//a)
char (*x[10])(int);

typedef char Fcn(int);
typedef Fcn *Fcn_ptr;
Fcn_ptr x[10];

//b)
int (*x(int))[5];

typedef int Arr[5];
typedef Arr *Arr_ptr;
Arr_ptr x(int);

//c)
float *(*x(void))(int);

typedef float *flt_ptr;
typedef flt_ptr Fcn(int);
typedef Fcn *Fcn_ptr;
Fcn_ptr x(void);

//d)
void (*x(int, void (*y)(int)))(int);

typedef void Fcn(int);
typedef Fcn *Fcn_ptr;
Fcn_ptr x(int, Fcn_ptr y);