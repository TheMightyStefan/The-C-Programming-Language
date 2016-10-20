#include <ctype.h>
#include <stdio.h>

int remove_spaces(char string[], int *index) {
    while (isspace(string[*index]) && string[*index] != '\n')
        *index++;

    return 0;
}

int get_float(double *pointer, char string[], int *index) {
    if (!isdigit(string[*index]) && string[*index] != EOF && string[*index] != '+' && string[*index] != '-')
        return 0;

    int sign = (string[*index] == '-') ? -1 : 1;
   
    if (string[*index] == '+' || string[*index] == '-') {
        if (isdigit(string[*index + 1])) {
            *index++;
        } else 
            return 0;
    }

    for (*pointer = 0; isdigit(string[*index]); *index++)
        *pointer = 10 * *pointer + (string[*index] - '0');

    double power = 1;

    if (string[*index] == '.') {
        index++;

        for (power = 1.0; isdigit(string[*index]); *index++) {
            *pointer = 10.0 * *pointer + (string[*index] - '0');
            power *= 10.0;
        }
    }
    *pointer = *pointer / power * sign;

    return 1;
}

int main() {
    char input[100];
    double number;
    int index = 0;

    for (int index = 0; input[index] != EOF; index++) {
        input[index] = getchar();
    }

    if (input[index] == '\n')
        input[index] = '\0';

    while (input[index] != '\0') {
        printf("\n%d", index);

        remove_spaces(input, &index);
        if (get_float(&number, input, &index))
            printf("Float : %g\n", number);
    }

    return 0;
}
