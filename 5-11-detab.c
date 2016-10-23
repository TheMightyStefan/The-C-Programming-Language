#include <stdlib.h>
#include <stdio.h>

int main (int argc, char **argv)
{
    char character;
    int charsBehindTabStop = 0;
    int arg_index = 1;

    while ((character = getchar()) != EOF) {
        int tabstop = atof(argv[arg_index]);

        printf("%d\n", tabstop);
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
 
