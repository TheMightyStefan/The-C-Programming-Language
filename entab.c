#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DEFAULT_TABSTOP 4
#define MAX_INPUT_SIZE 100

int main(int argc, char **argv) {
    char input[MAX_INPUT_SIZE];

    for (int index = 0; input[index] != '\n'; index++)
        input[index] = getchar();

    int length = strlen(input);

    int arg_index = 1;
    int tabstop = 0;
    
    if (arg_index > argc - 1)
        tabstop = DEFAULT_TABSTOP;
    else
        tabstop = atof(argv[arg_index++]);

    int index;
    int space_counter = 0;

    for (index = 0; index < length; index++) {
        if (input[index] == '*')
            space_counter++;
        else
            space_counter = 0;

        if (space_counter == tabstop) {
            index -= tabstop - 1;
            length -= tabstop - 1;
            input[index] = '\t';

            for (int move_index = index + 1; move_index < length; move_index++)
                input[move_index] = input[move_index + tabstop - 1];
                
            space_counter = 0;
            input[length - tabstop - 1] = '\0';
        }
    }

    printf("%s", input);
    return 0;
}
