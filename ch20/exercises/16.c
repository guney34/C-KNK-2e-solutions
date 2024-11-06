typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;

union {
    struct {
        DWORD eax, ebx, ecx, edx;
    } dword;
    struct {
        WORD ax, axh, bx, bxh, cx, cxh, dx, dxh;
    } word;
    struct {
        BYTE al, ah, ahl, ahh, bl, bh, bhl, bhh, cl, ch, chl, chh, dl, dh, bhl, bhh;
    } byte;
} regs;