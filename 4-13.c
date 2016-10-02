#include <string.h>
#include <stdio.h>

void swap(char string[], int index_1, int index_2) {
    int tmp = string[index_1];

    string[index_1] = string[index_2];
    string[index_2] = tmp;
}

void reverse(char string[], int index_from_start, int index_from_end) {
    if (index_from_start < index_from_end && index_from_start != index_from_end) {
        swap(string, index_from_start, index_from_end);

        reverse(string, index_from_start + 1, index_from_end - 1);
    }
}

int main() {
    char string[] = "Gigel scrie";

    reverse(string, 0, strlen(string) - 1);

    printf("%s\n", string);

    return 0;
}
