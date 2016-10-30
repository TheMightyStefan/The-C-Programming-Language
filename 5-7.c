#include <stdlib.h>
#include <stdio.h>

#define MAX_NUMBER_OF_LINES 50
#define MAX_LINE_LENGTH 50

void read_lines(char *line[], int *line_number) {
    int index = 0;

    line[*line_number][index]  = getchar();

    while(line[*line_number][index] != EOF) {
        if (line[*line_number][index] == '\n' || line[*line_number][index] == EOF) {
            line[*line_number][index] = '\0';
            ++*line_number;
            index = 0;
            
            line[*line_number][0] = getchar();
        } else
            line[*line_number][++index] = getchar();
    }
}

void write_lines(char *line[], int lines_to_write) {
    printf("\n");
    
    for (int index = 0; index < lines_to_write; index++)
        printf("%s\n", line[index]);
}

int main() {
    char **input = malloc(MAX_NUMBER_OF_LINES * sizeof(char *));

    for (int index = 0; index < MAX_NUMBER_OF_LINES; index++)
        input[index] = (char *)malloc(MAX_LINE_LENGTH + 1);

    int line_number = 0;

    read_lines(input, &line_number);

    write_lines(input, line_number);

    return 0;
}
