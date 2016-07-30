#include <stdio.h>
#include <stdlib.h>

int invert(int x, int p, int n) {

    // We make a copy of x for later use.
    int z = x;
    
    // We get the bit on position p to be 
    // the least significant one.
    x = x >> p;

    // We set the last n bits to 0.
    x = (x >> n) << n;

    // We change the last n bits with the 
    // inverted corespondent ones from the copy
    // of the original x.
    x = x | ~((~0 << n) | ((z >> p) & (~(~0 << n))));

    // We shift x back to get the most significant 
    // bit on the initial position.
    x = x << p;
    
    // We set the last p bits of x to 0.
    x = (x >> p) << p;

    // We change the last p bits of x
    // with the last p bits from the copy 
    // of the original x.
    x = x | ((z >> p) & (~(~0 << p)));

    // We return the needed x.
    return x;  
}

int main() {

    int x = 255;
    int p = 2;
    int n = 2;
    printf("\nx = %x\n", x);
    printf("\nInverted version : %x\n", invert(x, p, n));
    return 0;
}
