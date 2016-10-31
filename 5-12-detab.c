#include <stdlib.h>
#include <stdio.h>

#define DEFAULT_TABSTOP 4

int main (int argc, char **argv) {
    int tabstop = DEFAULT_TABSTOP;
    int start = 0;

    for (int arg_index = 1; arg_index < argc; arg_index++) {
        int temp = atoi(argv[arg_index]);
                              
        if (temp > 0)
            tabstop = temp;
        else if (temp < 0)
            start = -temp;
    }

    int character_index = 1;
    int charsBehindTabStop = 0;
    char character = getchar();

    while (character != '\n') {
        if (character == '\t' && character_index >= start)
            while (charsBehindTabStop < tabstop) {
                printf("*");
                charsBehindTabStop++;
            }
        else {
            printf("%c", character);
            charsBehindTabStop++;
        }
        
        if (charsBehindTabStop == tabstop)
            charsBehindTabStop = 0;

        character = getchar();
        character_index++;
    }

    return 0;
}
 
