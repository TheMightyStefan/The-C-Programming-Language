#include <stdio.h>
#include <stdlib.h>

int invert(int x, int p, int n) {

    return x ^ (~(~0 << n) << (p + 1 - n));
}

int main() {

    int x = 150;
    printf("\nx = %x\n", x);
    printf("\nInverted version : %x\n", invert(x, 2, 2));
    return 0;
}
