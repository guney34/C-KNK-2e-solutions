#define GET_RED(c) ((unsigned char)(c))
#define GET_GREEN(c) ((unsigned char)((c) >> 8 & 0xFFu))
#define GET_BLUE(c) ((unsigned char)((c) >> 16 & 0xFFu))