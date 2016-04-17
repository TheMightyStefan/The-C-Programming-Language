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
            charsBehindTabStop++;
            blanksRow = 1;
        } else {
            if (blanksRow == 1 && blanks > 0) {
                blanksRow = 0;
                while (blanks > 0) {
                    putchar(' ');
                    blanks--;
                }
            } else {
                charsBehindTabStop++;
                putchar(character);
            }
        }
        if (charsBehindTabStop == TABSTOP) {
            charsBehindTabStop = 0;
            blanks = 0;
            if (blanksRow == 1) {
                putchar('\t');
            }
        }
    }
    return 0;
}
