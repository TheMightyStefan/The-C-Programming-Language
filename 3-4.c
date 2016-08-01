#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

// The initial program could not print the 
// largest negative value because the limits
// of types in two's complement systems are
// -2^(n-1) and 2^(n-1) - 1, where n is the number
// of bits of the type.

// The assignment n = -n causes the issue because n can't
// handle -(-2^(n-1)) = 2^(n-1).

void reverse(char s[]) {

    int i, j, c;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[]) {

    int i = 0;
    int sign = n;

    do {
        s[i++] = abs(n % 10) + '0';
    } while ( n /= 10 );

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';

    reverse(s);
}


int main(void) {

    char string[20];
    
    printf("INT_MIN: %d\n", INT_MIN);
    
    itoa(INT_MIN, string);
    
    printf("Buffer : %s\n", string);
    
    return 0;
}
