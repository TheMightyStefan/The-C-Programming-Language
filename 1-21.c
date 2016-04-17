#include <stdio.h>
#define TABSTOP 8

// E plictisitoare problema.

int main ()
{
    int markerBlanksRow = 0, blanksInTheRow = 0;
    char character;
    int charsBehindTabStop = 0;
    while ((character = getchar()) != EOF) {
        if (character == ' ') {
            blanksInTheRow++;
            charsBehindTabStop++;
            markerBlanksRow = 1;
        } else {
            if (markerBlanksRow == 1 && blanksInTheRow > 0) {
                markerBlanksRow = 0;
                while (blanksInTheRow > 0) {
                    putchar(' ');
                    blanksInTheRow--;
                }
            } else {
                charsBehindTabStop++;
                putchar(character);
            }
        }
        if (charsBehindTabStop == TABSTOP) {
            charsBehindTabStop = 0;
            blanksInTheRow = 0;
            if (markerBlanksRow == 1) {
                putchar('\t');
            }
        }
    }
    return 0;
}