#include <stdio.h>
#include <stdlib.h>

int getbits(int y, int n) {

    // We get the last n bits of y
    return (y & (~0u >> ((sizeof(y) * 8 ) - n)));
}

int setbits(int x, int p, int n, int y) {
    
    // We make a copy of x for later uses.
    int z = x;

    // We get the last significant bit to be the one 
    // on the position p + n - 1, the last one we need to change. 
    x = x >> ((sizeof(x) * 2) - p - n - 1);

    // We change the last n bits of x after the shift 
    // with the last n bits of y.
    x = (x & ~n) | getbits(y, n);
    
    // We shift x back to get the most significant bit on the 
    // initial position.
    x <<= ((sizeof(x) * 2) - p - n - 1);
    
    // We change the last bits of x obtained after the shift
    // with the last bits of the initial x.
    x = (x & (~(sizeof(x) * 2) - p - n - 1)) | getbits(z, sizeof(x) * 2 - p - n - 1);
    
    // We return the needed x.
    return x;
}

int main() {
    
    int x = 150;
    int y = 85;
    printf("\nx = %x\ny = %x\n", x, y);
    printf("\nx final = %x\n", setbits(x, 3, 3, y));
    return 0;
}
    
    
