#include <stdio.h>
#include <string.h>

void string_copy(char copy[], char target[], int size) {
    while (*copy != '\0' && size) {
        *target++ = *copy++;
        size--;
    }

    *target = '\0';
}

void string_canonetation(char result[], char to_add[], int size) {
    int index = strlen(result);

    while (*to_add != '\0' && size) {
        *(result + index) = *to_add++;
        index++;
        size--;
    }

    *(result + index) = '\0';
}

int string_compare(char first[], char second[], int length) {
    int full_length = 0;
    int index = 0;

    if (length == strlen(second))
        full_length = 1;

    while (*(first + index) != '\0' && length) {
        if (*(second + index) == '\0')
            return 1;
    
        if (*(first + index) < *(second + index))
            return -1;

        if (*(first + index) > *(second + index))
            return 1;

        index++;
        length--;
    }

    if (*(second + index) != '\0' && full_length)
        return -1;

    return 0;

}
int main() {
    char string_1[] = "First String";
    char string_2[] = "Second String";

    printf("\n%d", string_compare(string_1, string_2, 12));

    string_canonetation(string_1, string_2, 4);

    printf("\n%s", string_1);

    string_copy(string_1, string_2, 4);

    printf("\n%s", string_2);

    return 0;
}
