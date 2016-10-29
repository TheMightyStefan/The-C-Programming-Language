#include <stdlib.h>
#include <stdio.h>

#define DEFAULT_TABSTOP 4

int main (int argc, char **argv) {
    char character = getchar();
    int arg_index = 1;
    int charsBehindTabStop = 0;

    while (character != '\n') {
        int tabstop = 0;

        if (arg_index > argc - 1)
            tabstop = DEFAULT_TABSTOP;
        else
            tabstop = atoi(argv[arg_index]);

        if (character == '\t')
            while (charsBehindTabStop < tabstop) {
                printf("*");
                charsBehindTabStop++;
            }
        else {
            printf("%c", character);
            charsBehindTabStop++;
        }
        
        if (charsBehindTabStop == tabstop) {
            charsBehindTabStop = 0;
            arg_index++;
        }

        character = getchar();
    }

    return 0;
}
 
