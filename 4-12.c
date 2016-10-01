#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void itoa(int number, char digit_string[]) {
    static int index = 0;

    if (number < 0) {
        digit_string[index] = '-';
        number = -number;
    }

    if (number / 10)
        itoa(number / 10, digit_string);
    else 
        index = 0;

    digit_string[++index] = abs(number) % 10 + '0';

    digit_string[index] = '\0';
}

void itoa2_operation(int number, char digit_string[], int index) {
    if (number / 10) {
        itoa2_operation(number / 10, digit_string, --index);
    } else if (digit_string[0] == '-')
        index = 1;
    else 
        index = 0;

    digit_string[index] = abs(number) % 10 + '0';

    digit_string[++index] = '\0';
}

void itoa2(int number, char digit_string[]) {
    int digits = 0;
    int number_copy = -number;

    while (number_copy != 0) {
        number_copy /= 10;
        digits++;
    }
    
    if (number < 0) {
        digit_string[0] = '-';
        number = -number;
        itoa2_operation(number, digit_string, digits + 1);
    } else
        itoa2_operation(number, digit_string, digits);
}

int main() {
    int number = 23423;
    char digit_string[100];

    itoa2(number, digit_string);

    printf("\n%s", digit_string);

    return 0;
}
