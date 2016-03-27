#include <stdio.h>

int main ()
{
    char character;
    while ((character = getchar()) != EOF) {
        if (character == '\t') {
                printf("    ");
            }
         else {
            printf("%c", character);
        }
    }
    return 0;
}
