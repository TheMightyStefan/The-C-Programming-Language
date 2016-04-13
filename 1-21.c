#include <stdio.h>
#define TABSTOP 8

// E plictisitoare problema.

int main ()
{
    int blanksRow = 0, blanks = 0;
    char character;
    int charsBehindTabStop = 0;
    while ((character = getchar()) != EOF) {
        if (character == ' ') {
            blanks++;
            blanksRow = 1;
            continue;
        } else {
            if (blanks > 0 && blanksRow == 1) {
                while (blanks > 0) {
                    putchar(' ');
                    blanks--;
                }
            }
            blanksRow = 0;
        }
        if (charsBehindTabStop == TABSTOP) {
            charsBehindTabStop = 0;
            if (blanksRow == 1) {
                putchar('\t');
            }
        } else {
            charsBehindTabStop++;
        }
        if (blanksRow == 0)
            putchar(character);
    }
    return 0;
}
