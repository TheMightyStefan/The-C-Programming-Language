#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char string[])
{
    for(int index_1 = 0, index_2 = strlen(string) - 1; index_1 < index_2; index_1++, index_2--) {
        int character = string[index_1];
        string[index_1] = string[index_2];
        string[index_2] = character;
    }
}

void itob(int number, char modified_number[], int base) {

    int index = 0;
    int negative = 0;    

    if (number < 0) {
        negative = 1;
        number = -number;
    }

    do {
        int rest = number % base;
        modified_number[index++] = rest <= 9 ? rest + '0' : rest + 'a' - 10;
    } while ((number /= base) > 0);

    if (negative) 
        modified_number[index++] = '-';    

    modified_number[index] = '\0';
    
    reverse(modified_number);
}

int main() {
 
    int number = 17056;
    char modified_number[50];
    int base = 20;

    itob(number, modified_number, base);

    printf("\n%s\n", modified_number);
    
    return 0;
}
