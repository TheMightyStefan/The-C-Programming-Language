#include <stdio.h>

int bitcount(int x) {

    int one_bits;

    while (x) {
        one_bits++;
        x &= (x-1);
    }
   
    return one_bits;
}

int main() {

    int x = 0xEE;
    
    printf("\n%d\n", bitcount(x));

    return 0;
} 
