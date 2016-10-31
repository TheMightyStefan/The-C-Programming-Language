#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DEFAULT_TABSTOP 4
#define MAX_INPUT_SIZE 100

int main(int argc, char **argv) {
    char input[MAX_INPUT_SIZE];
    int input_index = 0;

    input[input_index] = getchar();

    while (input[input_index] != '\n') {
       input[++input_index] = getchar();
    }

    input[input_index] = '\0';

    int length = strlen(input);

    int arg_index = 1;
    int tabstop = DEFAULT_TABSTOP;

    int start = 0;

    for (int arg_index = 1; arg_index < argc; arg_index++) {
        int temp = atoi(argv[arg_index]);
              
        if (temp > 0)
            tabstop = temp;
        else if (temp < 0)
            start = -temp;
    }
    
    int index;
    int space_counter = 0;

    for (index = start; index < length; index++) {
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
            input[length] = '\0';
        }
    }

    printf("%s", input);

    return 0;
}
