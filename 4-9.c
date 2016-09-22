#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 100

char buffer[100];
int buffer_index = 0;

void unget_character(int character) {
    if (buffer_index >= BUFFER_SIZE)
        printf("\nUngetch : Too many characters");
    else if (character != EOF)
        buffer[buffer_index++] = character;
}

int get_character() {
    if (buffer_index > 0)
        return buffer[--buffer_index];
    else
        return getchar();
}

int main() {
    unget_character(EOF);

    char character;

    while ((character = get_character()) != EOF) {
        printf("%c", character);
    }
       
    return 0;
}
