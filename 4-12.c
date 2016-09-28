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

void itoa2(int number, char digit_string[], int index) {
   if (number < 0) {
        digit_string[0] = '-';
        number = -number;
   }

   if (digit_string[0] != '-')
        digit_string[0] = '+';

   if (number / 10) {
        index--;
        itoa2(number / 10, digit_string, index);
    }
    else 
        index = 1;

    digit_string[index++] = abs(number) % 10 + '0';

    digit_string[index] = '\0';
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

int main() {
    int number = 24321;
    char digit_string[100];

    itoa2(number, digit_string, digit_counter(number));

    printf("\n%s", digit_string);

    return 0;
}
