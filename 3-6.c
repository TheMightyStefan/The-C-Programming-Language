#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

void reverse(char string[]) {

    for (int index_1 = 0, index_2 = strlen(string) - 1; index_1 < index_2; index_1++, index_2--) {
        int character = string[index_1];
        string[index_1] = string[index_2];
        string[index_2] = character;
    }
}

void itoa(int number, char digit_string[], int minimum_width) {

    int index = 0;
    int initial_number = number;

    do {
        digit_string[index++] = abs(number % 10) + '0';
    } while ( number /= 10 );

    if (initial_number < 0)
        digit_string[index++] = '-';

    while (index < minimum_width) {
        digit_string[index] = ' ';
        index++;
    } 

    digit_string[index] = '\0';
    reverse(digit_string);
}


int main(void) {

    char digit_string[100];
    int minimum_width = 20;

    printf("INT_MIN: %d\n", INT_MIN);

    itoa(INT_MIN, digit_string, minimum_width);

    printf("Buffer : %s\n", digit_string);

    return 0;
}

