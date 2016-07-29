#include <stdio.h>
#include <stdlib.h>

int getbits(int y, int n) {

    return (y & (~0u >> ((sizeof(y) * 8 ) - n)));
}

int setbits(int x, int p, int n, int y) {
    
    printf("\nSizeof x : %d\n", sizeof(x));
    int z = x;
    x = x >> ((sizeof(x) * 2) - p - n - 1);
    printf("\nx >> %ld = %x\n", (sizeof(x) * 2) - p - n - 1, x);
    x = (x & ~n) | getbits(y, n);
    printf("\nx + noii biti : %x\n", x);
    x <<= ((sizeof(x) * 2) - p - n - 1);
    printf("\nx << %ld = %x\n", (sizeof(x) * 2) - p - n - 1, x);
    x = (x & (~(sizeof(x) * 2) - p - n - 1)) | getbits(z, sizeof(x) * 2 - p - n - 1);
    return x;
}

int main() {
    
    int x = 150;
    int y = 85;
    printf("\nx = %x\ny = %x\n", x, y);
    printf("\nx final = %x\n", setbits(x, 3, 3, y));
    return 0;
}
    
    
