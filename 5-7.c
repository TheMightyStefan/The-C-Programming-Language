#include <stdlib.h>
#include <stdio.h>

#define MAX_NUMBER_OF_LINES 50

void read_lines(char *line[], int *line_number) {
    int index = 0;

    line[*line_number][index]  = getchar();

    while(line[*line_number][index] != EOF) {
        if (line[*line_number][index] == '\n' || line[*line_number][index] == EOF) {
            line[*line_number][index] = '\0';
            ++*line_number;
            index = 0;
            
            printf("\nLINE NUMBER : %d\n", *line_number);

            line[*line_number][0] = getchar();

            printf("\nCHAR : %c\n", line[*line_number][index]);
        } else {
            line[*line_number][++index] = getchar();
            
            printf("\nCHAR\n");
        }
    }
}

void write_lines(char *line[], int lines_to_write) {
    for (int index = 0; index < lines_to_write; index++)
        printf("%s\n", line[index]);
}

int main() {
    char *input[MAX_NUMBER_OF_LINES];
    int line_number = 0;

    read_lines(input, &line_number);

    write_lines(input, line_number);

    return 0;
}
