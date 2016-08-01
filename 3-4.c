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

void reverse(char string[]) {

    for (int index_1 = 0, index_2 = strlen(string) - 1; index_1 < index_2; index_1++, index_2--) {
        int character = string[index_1];
        string[index_1] = string[index_2];
        string[index_2] = character;
    }
}

void itoa(int number, char digit_string[]) {

    int index = 0;
    int initial_number = number;

    do {
        digit_string[index++] = abs(number % 10) + '0';
    } while ( number /= 10 );

    if (initial_number < 0)
        digit_string[index++] = '-';

    digit_string[index] = '\0';

    reverse(digit_string);
}


int main(void) {

    char digit_string[20];
    
    printf("INT_MIN: %d\n", INT_MIN);
    
    itoa(INT_MIN, digit_string);
    
    printf("Buffer : %s\n", digit_string);
    
    return 0;
}
