#include <stdio.h>
#define TABSTOP 8

int main ()
{
    int blanksInTheRow, rowOfBlanksMarker, charsBehindTabstop;
    char character;
    while ((character = getchar()) != EOF) {
        if (character == '*') {
            blanksInTheRow++;
            rowOfBlanksMarker = 1;
        } else {
            if (rowOfBlanksMarker == 1) {
                while (blanksInTheRow > 0) {
                    putchar('*');
                    blanksInTheRow--;
                    charsBehindTabstop++;
                }
                rowOfBlanksMarker = 0;
            } else {
                putchar(character);
                charsBehindTabstop++;
            }
        }
        if (charsBehindTabstop == TABSTOP) {
            charsBehindTabstop = 0;
            blanksInTheRow = 0;
            if (rowOfBlanksMarker == 1) {
                putchar('\t');
            }
        }
    }
    return 0;
}