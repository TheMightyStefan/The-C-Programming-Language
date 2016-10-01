#include <string.h>
#include <stdio.h>

void reverse(char string[], int index_from_start, int index_from_end) {
    char tmp;

    if (index_from_start < index_from_end && index_from_start != index_from_end) {
        tmp = string[index_from_start];
        string[index_from_start] = string[index_from_end];
        string[index_from_end] = tmp;

        index_from_start++;
        index_from_end--;

        reverse(string, index_from_start, index_from_end);
    }
}

int main() {
    char string[] = "Gigel scrie";

    reverse(string, 0, strlen(string) - 1);

    printf("%s\n", string);

    return 0;
}
