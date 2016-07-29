#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
int setbits(int x, int p, int n, int y) {
    
    return x & ~(~(~0 << n) << (p+1-n)) | ((y & ~(~0<<n)) << (p+1-n));
=======
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
>>>>>>> parent of e694c60... Finished
}

int main() {
    
<<<<<<< HEAD
    int x = 150;
    int y = 85;
    printf("\nx = %x\ny = %x\n", x, y);
    printf("\nx final = %x\n", setbits(x, 3, 3, y));
=======
    int y = 453; 
    showbits(64);
    showbits(86);
    showbits(43);
    showbits(432);
    showbits(getbits(y,3));
>>>>>>> parent of e694c60... Finished
    return 0;
}
