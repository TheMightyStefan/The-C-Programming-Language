#include <stdio.h>
#include <stdlib.h>

int setbits(int x, int p, int n, int y) {
    
    return x & ~(~(~0 << n) << (p+1-n)) | (( y & ~(~0<<n)) << (p+1-n));
}

int main() {
    
    int x = 150;
    int y = 85;
    printf("\nx = %x\ny = %x\n", x, y);
    printf("\nx final = %x\n", setbits(x, 3, 3, y));
    return 0;
}
