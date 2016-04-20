#include <stdio.h>
#include <ctype.h>
#define LAST_COLUMN_OF_INPUT 15

int main ()
{
    char line[LAST_COLUMN_OF_INPUT];
    char character;
    int charOnTheLine = 0, blanksBeforeFold = 0;
    while ((character = getchar()) != EOF) {
        if (charOnTheLine < LAST_COLUMN_OF_INPUT) {
            line[charOnTheLine] = character;
            charOnTheLine++;
        }
        if (charOnTheLine == LAST_COLUMN_OF_INPUT) {
           while (isspace(line[charOnTheLine-1])) {
                blanksBeforeFold++;
                charOnTheLine--;
           }
           for (charOnTheLine = 0; charOnTheLine < (LAST_COLUMN_OF_INPUT - blanksBeforeFold); charOnTheLine ++) {
                putchar(line[charOnTheLine]);
           }
           blanksBeforeFold = 0;
           charOnTheLine = 0;
           putchar('\n');
        }
    }
    if ((character = getchar()) == EOF) {
        for (int index = 0; index < charOnTheLine; index++) {
                putchar(line[index]);
        }
    }
    return 0;
}