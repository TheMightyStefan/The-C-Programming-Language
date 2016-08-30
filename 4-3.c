#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_OPERATORS 100
#define NUMBER '0'
#define MAX_STACK_SIZE 100
#define BUFFER_SIZE 100

int stack_index = 0;
double stack[MAX_STACK_SIZE];
char buffer[BUFFER_SIZE];
int buffer_index = 0;

// Function for pushing into stack
void push(double new_stack_number) {
    if (stack_index < MAX_STACK_SIZE)
        stack[stack_index++] = new_stack_number;
    else
        printf("Error : Stack full\n");
}

//Function for poping from stack
double pop() {
    if (stack_index > 0) 
        return stack[--stack_index];
    else {
        printf("Error : Stack empty\n");
        return 0;
    }
}

//Function for getting input characters
int get_character() {
    return (buffer_index > 0) ? buffer[--buffer_index] : getchar();
}

//Function to "undo" get_character()
void unget_character(int character) {
    if (buffer_index >= BUFFER_SIZE)
        printf("Ungetch : Too many characters\n");
    else
        buffer[buffer_index++] = character;
}

//Function to get the type of input : Number / Operators
int get_operators(char input_string[]) {
    int string_index = 0;
    int character;

    //Ignore the spaces beetween characters
    while ((input_string[0] = character = get_character()) == ' ' || character == '\t');

    input_string[1] = '\0';

    //Return the operator, except in case of '-'
    if (!isdigit(character) && character != '.' && character != '-')
        return character;

    if (character != '-') {
        //Get the integer part
        if (isdigit(character))
            while (isdigit(input_string[++string_index] = character = get_character()));
        //Get the fractional part
        if (character == '.')
            while (isdigit(input_string[++string_index] = character = get_character()));

        input_string[string_index] = '\0';

        if (character != EOF)
            unget_character(character);

        return NUMBER;

    } else {
            if (stack_index < 2) {
            //Negative number
            input_string[0] = '-';

            //Get integer part
            while (isdigit(input_string[++string_index] = character = get_character()));

            //Get fractional part
            if (character == '.')
                while (isdigit(input_string[++string_index] = character = get_character()));

            input_string[string_index] = '\0';

            if (character != EOF) {
                unget_character(character);
            }

            return NUMBER;
            } else {
            //Subtraction
            return '-';
            }
        }
}

int main() {
    int type;
    double next_pop;
    char input_string[MAX_OPERATORS];

    while ((type = get_operators(input_string)) != EOF) {
            switch(type) {
            //Push the number into the stack
                case NUMBER:
                    push(atof(input_string));
                    break;
            //Do the requested operations
                case '+':
                    push(pop() + pop());
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '-':
                    next_pop = pop();
                    push(pop() - next_pop);
                    break;
                case '/':
                    next_pop = pop();
                    if (next_pop != 0)
                        push(pop() / next_pop);
                    else
                        printf("Error : 0 divisor\n");
                    break;
                case '%':
                    next_pop = pop();
                    if (next_pop != 0)
                        push((int)pop() % (int)next_pop);
                    else
                        printf("Error : 0 divisor\n");
                    break;
                case '\n':
            //Print output
                    printf("\t%g\n", pop());
                    break;
                default:
                    printf("Error : Unknown command %s\n", input_string);
                    break;
        }
    }

    return 0;
}
