#define A(x) ((x) * (x))
// would fail if the argument is not an arithmetic type

#define B(x) ((x) % 4)
// would fail if the argument is not an integer type

#define C(x, y) ((x) * (y) < 100)
// would fail if the argument is not an arithmetic type