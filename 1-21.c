#include <stdio.h>
#define TABSTOP 8

int main ()
{
    int OK = 0;
    char character;
    int charsBehindTabStop = 0;
    while ((character = getchar()) != EOF) {
        if (character == "*") {
            OK = 1;
            continue;
        }
        else {
            printf("%c", character);
            OK = 0;
        }
        while (charsBehindTabStop < TABSTOP) {
                charsBehindTabStop++;
            }
        if (charsBehindTabStop == TABSTOP && OK == 1) {
            charsBehindTabStop = 0;
            printf("\t");
        }
    }
    return 0;
}
