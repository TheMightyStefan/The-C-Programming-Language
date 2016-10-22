#include <stdio.h>
#include <string.h>

void string_concatenation(char result[], char to_add[]) {
    int len = strlen(result);

    for (int index = 0; index != strlen(to_add); index++) 
        result[index + len] = to_add[index];
}

int main() {
    char result[100] = "Ionel il cheama pe ";
    char to_add[] = "Gigel";

    string_concatenation(result, to_add);

    printf("\n%s", result);

    return 0;
}
