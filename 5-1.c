#include <ctype.h>
#include <stdio.h>

#define BUFFER_SIZE 100

int buffer_index = 0;
int buffer[100];

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

int get_integer(int *pointer) {
    int character = get_character();
    int sign;

    while (isspace(character)) 
        character = get_character();

    if (!isdigit(character) && character != EOF && character != '+' && character != '-') {
        unget_character(character);
        return 0;
    }
    sign = (character == '-') ? -1 : 1;
   
    if (character == '+' || character == '-')
        character = get_character();

    for (*pointer = 0; isdigit(character); character = get_character())
        *pointer = 10 * *pointer + (character - '0');

    *pointer *= sign;

    if (character != EOF)
        unget_character(character);

    return 1;
}

int main() {
    char character;
    int number;
    
    while (character != EOF) {
        if (get_integer(&number))
            printf("\nInt : %d", number);
        
        character = get_character();
    }

    return 0;
}
