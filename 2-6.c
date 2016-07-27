#include <stdio.h>
#include <stdlib.h>

int getbits(int y, int n) {

    return (y & (~0u >> ((sizeof(y) * 8 ) - n)));
}

int setbits(int x, int p, int n, int y) {

    int z = x;
    x >>= ((sizeof(x) * 8) - p - n + 1);
    x = (x & ~n) | getbits(y, n);
    x <<= ((sizeof(x) * 8) - p - n + 1);
    x = (x & (~(sizeof(x) * 8) - p - n + 1)) | getbits(z, sizeof(x) * 8 - p - n + 1);
    return x;
}

int main() {
    
    int x = 41;
    int y = 29;
    printf("\n%x\n%x\n", x, y);
    printf("%x\n", setbits(x, 3, 3, y));
    return 0;
}
    
    
