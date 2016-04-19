#include <stdio.h>
#include <ctype.h>
#define LAST_COLUMN_OF_INPUT 15

int main ()
{
    char line[LAST_COLUMN_OF_INPUT];
    char character;
    int charOnTheLine, blanksBeforeFold;
    while ((character = getchar()) != EOF) {
        if (charOnTheLine < LAST_COLUMN_OF_INPUT) {
            line[charOnTheLine] = character;
            charOnTheLine++;
        }
        if (charOnTheLine == LAST_COLUMN_OF_INPUT) {
           while (isspace(line[charOnTheLine])) {
                blanksBeforeFold++;
                charOnTheLine--;
           }
           for (charOnTheLine = 0; charOnTheLine < (LAST_COLUMN_OF_INPUT - blanksBeforeFold); charOnTheLine ++) {
                putchar(line[charOnTheLine]);
           }
           for (charOnTheLine = 0; charOnTheLine < (LAST_COLUMN_OF_INPUT - blanksBeforeFold); charOnTheLine ++)
                line[charOnTheLine] = 0;
           charOnTheLine = 0;
           putchar('\n');
        }
    }
    return 0;
}
