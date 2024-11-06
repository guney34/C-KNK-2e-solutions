// a)
#define CHECK(x,y,n) ((x) >= 0 && (x) <= ((n) - 1) && (y) >= 0 && (y) <= ((n) - 1))
// b)
#define MEDIAN(x,y,z) ((y) <= (z) ? \
                       ((z) <= (x) ? (z) : ((x) <= (y) ? (y) : (x))) : \
                       ((y) <= (x) ? (y) : ((x) <= (z) ? (z) : (x))))
// c)
#define POLYNOMIAL(x) (3*(x)*(x)*(x)*(x)*(x) \
                       + 2*(x)*(x)*(x)*(x) \
                       - 5*(x)*(x)*(x) \
                       - (x)*(x) \
                       - 6)