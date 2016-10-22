#include <stdio.h>
#include <string.h>

void string_concatenation(char result[], char to_add[]) {
    int index = 0;
    int len = strlen(result);

    while (index != strlen(to_add)) { 
        result[index + len] = to_add[index];
        index++;
    }
}

int main() {
    char result[100] = "Ionel il cheama pe ";
    char to_add[] = "Gigel";

    string_concatenation(result, to_add);

    printf("\n%s", result);

    return 0;
}
