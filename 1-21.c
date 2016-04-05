#include <stdio.h>
#define TABSTOP 8

int main ()
{
    int blanksRow = 0;
    char character;
    int charsBehindTabStop = 0;
    while ((character = getchar()) != EOF) {
        if (character == " " && blanksRow == 1) {
            blanksRow = 1;
        } else if (character == " " && blanksRow == 0) {
            blanksRow = 1;
        } else if (character != " ") {
            printf("%c",character);
            blanksRow = 0;
        }
        while (charsBehindTabStop < TABSTOP) {
            charsBehindTabStop++;
        }
        if (charsBehindTabStop == TABSTOP) {
            charsBehindTabStop = 0;
            if (blanksRow == 1) {
                printf("\t");
            }
        }
    }
    return 0;
}