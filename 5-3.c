#include <stdio.h>
#include <string.h>

void string_concatenation(char result[], char to_add[]) {
    for (int index = strlen(result); *to_add != '\0'; index++)
        *(result + index) = *to_add++;
}

int main() {
    char result[] = "Ionel il cheama pe ";
    char to_add[] = "Gigel";

    string_concatenation(result, to_add);

    printf("\n%s", result);

    return 0;
}
