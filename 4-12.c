#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void itoa(int number, char digit_string[]) {
    static int index;

    if (number / 10)
        itoa(number / 10, digit_string);
    else {
        index = 0;
        if (number < 0)
            digit_string[index++] = '-';
    }

    digit_string[index++] = abs(number) % 10 + '0';

    digit_string[index] = '\0';
}

int main() {
    int number = 10021;
    char digit_string[100];

    itoa(number, digit_string);

    printf("\n%s", digit_string);

    return 0;
}
