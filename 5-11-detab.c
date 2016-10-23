#include <stdlib.h>
#include <stdio.h>

#define DEFAULT_TAB_STOP 4

int main (int argc, char **argv) {
    char character;
    int arg_index = 1;
    int charsBehindTabStop = 0;

    while ((character = getchar()) != '\n') {
        int tabstop = 0;

        if (arg_index > argc - 1)
            tabstop = DEFAULT_TAB_STOP;
        else {
            tabstop = atof(argv[arg_index]);
        }

        if (character == '\t') {
            while (charsBehindTabStop < tabstop) {
                printf("*");
                charsBehindTabStop++;
            }
        } else {
            printf("%c", character);
            charsBehindTabStop++;
        }
        
        if (charsBehindTabStop == tabstop) {
            charsBehindTabStop = 0;
            arg_index++;
        }
       
    }

    return 0;
}
 
