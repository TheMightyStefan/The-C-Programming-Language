#include <stdio.h>

int rightrot(int x, int n) {

    int x_copy = x;

    // We store the last n bits of x in last_bits.
    int last_bits = x & ~(~0 << n);
    
    // We delete the last n bits of x.
    x = x >> n;
    
    // We initialize bits_number, which will store the 
    // number of the bits of x after the delete.
    int bits_number = 0;

    // We get the number of bits and x becomes 0.
    while (x) {
        x = x >> 1;
        bits_number++;
    }

    // We add the rotated bits in the right of x.
    x = x | last_bits;
    
    // We left shift it to get the rotated bits 
    // to be the most significant ones.
    x = x << bits_number;

    // We add the left bits from the initial x to
    // the modified x.
    x = x | (x_copy >> n);

    // We return the needed x.
    return x;
}

int main() {

    int x = 170;
    int n = 3;

    printf("\n%x --> %x\n", x, rightrot(x, n));

    return 0;
}
