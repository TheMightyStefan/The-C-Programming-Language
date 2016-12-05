#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int character = getchar();

    if (strcmp(argv[0], "./lower") == 0)
        while (character != EOF) {
            putchar(tolower(character));

            character = getchar();
        }
    else if (strcmp(argv[0], "./upper") == 0)
        while (character != EOF) {
            putchar(toupper(character));

            character = getchar();
        } 
    else 
        //Using lower by default if no specific name is included 
        while (character != EOF) {
            putchar(tolower(character));
    
            character = getchar();
        }
    
    return 0;
} 
