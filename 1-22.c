#include <stdio.h>
#define LAST_COLUMN_OF_INPUT 15

int main()
{
    char character;
    unsigned short int charactersOnTheLine;
    while ((character = getchar()) != EOF) {
            charactersOnTheLine++;
            if (charactersOnTheLine < LAST_COLUMN_OF_INPUT && (character != " " || character != "\t"))
                printf("%c", character);
            else if (charactersOnTheLine > LAST_COLUMN_OF_INPUT) {
                printf("\n");
                charactersOnTheLine = 0;
            }
    }
    return 0;
}
