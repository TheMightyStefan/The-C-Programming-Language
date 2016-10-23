#include <stdio.h>

int main (int argc, char **argv)
{
    char character;
    int charsBehindTabStop = 0;
    int arg_index = 0;

    while ((character = getchar()) != EOF) {
        if (character == '\t') {
            while (charsBehindTabStop < argv[arg_index][0]) {
                printf(" ");
                charsBehindTabStop++;
            }
        } else {
            printf("%c", character);
            charsBehindTabStop++;
        }
        
        if (charsBehindTabStop == argv[arg_index][0]) {
            charsBehindTabStop = 0;
            arg_index++;
        }
    }

    return 0;
}
 
