#include <stdio.h>
#include <stdlib.h>

void showbits(int number) {
    
    int binary[100], index = 0;
    while (number) {
        if (number & 0x1) 
            binary[index] = 1;
        else
            binary[index] = 0;
        number >>= 1;
        index++;
    }
    printf("\n");
    for ( ; index >= 0; index--) {
        printf("%d", binary[index]);
    }
    printf("\n");
}

int getbits(int y, int n) {

    return (y & (~0u >> ((sizeof(y) * 8 ) - n)));
}

int main() {
    
    int y = 453; 
    showbits(64);
    showbits(86);
    showbits(43);
    showbits(432);
    showbits(getbits(y,3));
    return 0;
}
    
    
