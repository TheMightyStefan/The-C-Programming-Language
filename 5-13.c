#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_LINES 50
#define MAX_LINE_LENGTH 100

int main(int argc, char **argv) {
    char input[50][100];
    int line = 0;
    int index = 0;

    input[line][index] = getchar();

    while (input[line][index] != EOF && line <= MAX_LINES) {
        while (index < MAX_LINE_LENGTH && input[line][index] != '\n' && input[line][index] != EOF)
            input[line][++index] = getchar();

        if (input[line][index] == '\n') {
            input[line][index] = '\0';
            line++;  
            index = -1;
        }
    }

    input[line][index] = '\0';

    int needed_lines = atoi(argv[1]);

    while (needed_lines + 1 > 0) {
        printf("%s\n", input[line]);

        line--;
        needed_lines--;
    }

    return 0;
}
      
