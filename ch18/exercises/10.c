//a)
char *(*p)(char *);

//b)
void (*f(struct t *p, long n))(void);

//c)
void (*a[4])(void) = {insert, search, update, print};

//d)
struct t (*b[10])(int, int);