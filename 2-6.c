#include <stdio.h>
#include <stdlib.h>

void showbits(int number) {
    
    while (number) {
        if (number & 1) 
            printf("1");
        else
            printf("0");
        number >>= 1;
    }
    printf("\n");
}

int getbits(int y, int n) {

    return (y & (~0u >> ((sizeof(y) * 8 ) - n)));
}

int main() {
    
    int y = 144;
    showbits(y);
    showbits(getbits(y,3));
    return 0;
}
    
    
