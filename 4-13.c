#include <string.h>
#include <stdio.h>

void reverse(char string[]) {
    static int index_1 = 0;
    static int index_2 = 0;
    char tmp = 'a';

    for (int index = 1; index_2 == 0; index++)
        if (string[index] == '\0')
            index_2 = index - 1;

    if (index_1 < index_2 && index_1 != index_2) {
        tmp = string[index_1];
        string[index_1] = string[index_2];
        string[index_2] = tmp;

        index_1++;
        index_2--;

        reverse(string);
    }
}

int main() {
    char string[] = "Gigel scrie";

    reverse(string);

    printf("%s\n", string);

    return 0;
}
