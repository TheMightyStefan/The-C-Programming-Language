#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define GET_RESULT '\n'

#define ERROR 1
#define ARITH 2
#define MATH 3
#define STACK 4

#define NUMBER '0'

int change_variable = 0;

int get_type(char input_string[]) {
    int character;
    static int last_character = 0;

    if (last_character == 0)
        character = get_character();
    else {
        character = last_character;
        last_character = 0;
    }
    
    change_variable = 0;
    // Ignore the spaces beetween characters
    while (isspace(character) && character != GET_RESULT)
        character = get_character();

    if (isalpha(character)) {
        int string_index = 0;

        while (isalpha(character)) {
            input_string[string_index++] = character;
            character = get_character();
        }

        input_string[string_index] = '\0';

        if (character != EOF)
            last_character = character;

        if (strlen(input_string) > 1) {
            return MATH;
        } else if ((isalpha(input_string[0]) && input_string[0] != CHANGE_VARIABLE) || input_string[0] == GET_LAST_VARIABLE)
            return VARIABLE;
        else if (input_string[0] == CHANGE_VARIABLE) {
            change_variable = 1;
            
            do {
                input_string[0] = get_character();
            } while (input_string[0] == ' ');

                if (isalpha(input_string[0])) {
                    return VARIABLE;
                } else 
                    printf("Invalid change of variable\n");
        } else 
            return STACK;
        
    }
    if (character == GET_RESULT)
        return GET_RESULT;

    if ((character != '-' && isdigit(character)) || (character == '-' && stack_index < 2)) {
        input_string[0] = character;
        get_digits(input_string);
        return NUMBER;
    }

    if (!isdigit(character) && !isalpha(character) && character != '.') {
        input_string[0] = character;
        return ARITH;
    }
    // If something goes wrong
    return ERROR;
}
