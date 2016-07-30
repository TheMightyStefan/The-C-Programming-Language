#include <stdio.h>
#include <stdlib.h>

int getbits(int y, int n) {

    // We get the last n bits of y
    return y & (~(~0 << n));
}

int setbits(int x, int p, int n, int y) {
    
    // We make a copy of x for later use.
    int z = x;

    // We get the bit on the position p to be the last  
    // significant one. 
    x = x >> p;

    // We change the last n bits of x after the shift 
    // with the last n bits of y.
    x = ((x >> n) << n) | getbits(y, n);
    
    // We shift x back to get the most significant bit on the 
    // initial position.
    x = x << p;
    
    // We change the last bits of x obtained after the shift
    // with the last bits of the initial x.
    x = ((x >> p) << p) | getbits(z, p);
    
    // We return the needed x.
    return x;
}

int main() {
    
    int y = 0;
    int n = 4;
    int p = 3;
    int x = 255;
    printf("\nx = %x\ny = %x\n", x, y);
    printf("\nx final = %x\n", setbits(x, p, n, y));
    return 0;
}
    
    
