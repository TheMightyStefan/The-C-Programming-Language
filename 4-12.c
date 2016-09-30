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

void itoa2_operation(int number, char digit_string[], int index, int sign) {
    if (number / 10) {
        index--;
        itoa2_operation(number / 10, digit_string, index, sign);
    } else 
        index = sign;

    printf("\n%d -> %c", index, digit_string[index]);

    digit_string[index] = abs(number) % 10 + '0';

    digit_string[++index] = '\0';
}

int digit_counter(int number) {
    int digits = 0;

    if (number < 0) {
        digits++;
        number = -number;
    }

    while (number > 0) {
        number /= 10;
        digits++;
    }

    return digits;
}

void itoa2(int number, char digit_string[]) {
    if (number < 0) {
        digit_string[0] = '-';
        number = -number;
        itoa2_operation(number, digit_string, digit_counter(number), 1);
    } else
        itoa2_operation(number, digit_string, digit_counter(number), 0);
}

int main() {
    int number = -221;
    char digit_string[100];

    itoa2(number, digit_string);

    printf("\n%s", digit_string);

    return 0;
}
