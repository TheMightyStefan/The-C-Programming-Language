#include <stdio.h>
#include <string.h>

void string_copy(char copy[], char target[], int length) {
    for ( ; *copy != '\0' && length; length--) 
        *target++ = *copy++;

    *target = '\0';
}

void string_concanetation(char result[], char to_add[], int length) {
    int index = strlen(result);

    for ( ; *to_add != '\0' && length; index++, length--)
        *(result + index) = *to_add++;

    *(result + index) = '\0';
}

int string_compare(char first[], char second[], int length) {
    int full_length = 0;
    int index = 0;

    if (length == strlen(second))
        full_length = 1;

    for ( ; *(first + index) != '\0' && length; index++, length--) {
        if (*(second + index) == '\0')
            return 1;
    
        if (*(first + index) < *(second + index))
            return -1;

        if (*(first + index) > *(second + index))
            return 1;
    }

    if (*(second + index) != '\0' && full_length)
        return -1;

    return 0;

}
int main() {
    char string_1[100] = "First String";
    char string_2[100] = "Second String";

    printf("%d\n", string_compare(string_1, string_2, 12));

    string_concanetation(string_1, string_2, 4);

    printf("%s\n", string_1);

    string_copy(string_1, string_2, 4);

    printf("%s\n", string_2);

    return 0;
}
