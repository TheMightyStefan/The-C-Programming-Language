#include <stdio.h>
#include <string.h>

void string_concatenation(char result[], char to_add[]) {
    int index = strlen(result);

    while (*to_add != '\0') {
        *(result + index) = *to_add++;
        index++;
    }
}

int main() {
    char result[] = "Ionel il cheama pe ";
    char to_add[] = "Gigel";

    string_concatenation(&result[0], &to_add[0]);

    printf("\n%s", result);

    return 0;
}
