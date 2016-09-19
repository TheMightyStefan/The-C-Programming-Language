#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 100

char buffer[100];
int buffer_index = 0;

void unget_character(int character) {
        if (buffer_index >= BUFFER_SIZE)
                printf("\nUngetch : Too many characters");
        else
                buffer[buffer_index++] = character;
}

int get_character() {
        if (buffer_index > 0)
                return buffer[--buffer_index];
        else
                return getchar();
}

void unget_string(char string[]) {
        int size = strlen(string);

        while (size > 0)
                unget_character(string[--size]);
}

int main() {
        
        unget_string("abcdef");

        char character;

        do {
                character = get_character();
                printf("%c", character);
        } while (character != 'f');

        return 0;
}
