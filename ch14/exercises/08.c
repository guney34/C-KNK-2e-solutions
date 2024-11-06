#define STRINGIZE(x) #x
#define STRINGIZE2(x) STRINGIZE(x)
#define LINE_FILE ("Line " STRINGIZE2(__LINE__) " of file " __FILE__)