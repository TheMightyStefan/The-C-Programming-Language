#include <stdlib.h>

void unget_character(int character) {
        if (buffer_index >= BUFFER_SIZE)
                printf("\nUngetch : Too many characters");
        else
                buffer[buffer_index++] = character;
}

void unget_string(char string[]) {
        int size = strlen(string);

        while (size > 0)
                unget_character(string[--size]);
}
