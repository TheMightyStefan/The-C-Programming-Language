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
        } else {
            printf("%c", character);
            charsBehindTabStop++;
        }
        if (charsBehindTabStop == TABSTOP)
            charsBehindTabStop = 0;
    }
    return 0;
}
 
