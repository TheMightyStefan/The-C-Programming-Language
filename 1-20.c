#include <stdio.h>
#define TABSTOP 8

int main ()
{
    char character;
    int charsBehindTabStop = 0;
    while ((character = getchar()) != EOF) {
        if (character == '\t') {
            while (charsBehindTabStop < TABSTOP) {
                printf(" ");
                charsBehindTabStop++;
                }
            if (charsBehindTabStop == TABSTOP)
                charsBehindTabStop = 0;
        } else {
            printf("%c", character);
            charsBehindTabStop++;
        }
    }
    return 0;
}
