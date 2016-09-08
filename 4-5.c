#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>


// Command to print the top element of the stack
#define PRINT 'P'

// Command to duplicate the top element of the stack
#define DUPLICATE 'D'

// Command to clear the stack
#define CLEAR 'C'

// Command to switch the top elements of the stack
#define SWITCH 'S'

#define ARITH ':'
#define MATH ';'
#define STACK '&'

#define MAX_OPERATORS 100
#define NUMBER '0'
#define MAX_STACK_SIZE 100
#define BUFFER_SIZE 100

int stack_index = 0;
double stack[MAX_STACK_SIZE];
char buffer[BUFFER_SIZE];
int buffer_index = 0;
char key_character;

// Function for pushing into stack
void push(double new_stack_number) {
    if (stack_index < MAX_STACK_SIZE)
        stack[stack_index++] = new_stack_number;
    else
        printf("Error : Stack full\n");
}

// Function for poping from stack
double pop() {
    if (stack_index > 0)
        return stack[--stack_index];
    else {
        printf("Error : Stack empty\n");
        return 0;
    }
}

// Function for getting input characters
int get_character() {
    if (buffer_index > 0)
        return  buffer[--buffer_index];
    else
        return getchar();
}

// Function to "undo" get_character()
void unget_character(int character) {
    if (buffer_index >= BUFFER_SIZE)
        printf("Ungetch : Too many characters\n");
    else
        buffer[buffer_index++] = character;
}

// Function to get the digits of a number
void get_digits(char string[]) {
    int string_index = 0;

    do {
        string[++string_index] = get_character();
    } while (isdigit(string[string_index]) || string[string_index] == '.');

    if (string[string_index] != EOF)
        unget_character(string[string_index]);

    string[string_index] = '\0';
}

// Function to get the type of input : Number / Operators
int get_operators(char input_string[]) {
    int character = get_character();

    // Ignore the spaces beetween characters
    while (isspace(character) && character != '\n')
        character = get_character();

    if (isalpha(character)) {
        int string_index = 0;
        
        while (isalpha(character)) {
            input_string[string_index++] = character;
            character = get_character();
        }
  
        input_string[string_index] = '\0';

        if (character != EOF)
            unget_character(character);
        
        if (strlen(input_string) > 1)
            return MATH;
        else {
            key_character = input_string[0];
            return STACK;
        }
    }
    if (character == '\n')
        return '\n';
    // Return the operator, except in case of '-'
    if (!isdigit(character) && !isalpha(character) && character != '.' && character != '-') {
        key_character = character;
        return ARITH;
    }

    if (character != '-') {
        input_string[0] = character;
        get_digits(input_string);
        return NUMBER;
    } else if (stack_index < 2) {
        input_string[0] = '-';
        get_digits(input_string);
        return NUMBER;
    } else {
        key_character = character;
        return ARITH;
    }
}

double top() {
    if (stack_index > 0) {
        return stack[stack_index - 1]; 
    }
    else {
        printf("Error : Stack empty\n");
        return 0;
    }
}

char get_operation_or_stack_command(char operator_or_command) {
    return operator_or_command; 
}

void clear_stack() {
    stack_index = 0;
}

int main() {
    int type;

    do {
        double first_operand;
        double second_operand;
        char input_string[MAX_OPERATORS];
        type = get_operators(input_string);
        switch (type) {
            // Push the number into the stack
            case NUMBER:
                push(atof(input_string));
                break;
            case MATH:
                if (strcmp(input_string, "sin") == 0)
                    push(sin(pop()));
                else if (strcmp(input_string, "cos") == 0)
                    push(cos(pop()));
                else if (strcmp(input_string, "exp") == 0)
                    push(exp(pop()));
                else if (strcmp(input_string, "pow") == 0) {
                        first_operand = pop();
                        second_operand = pop();
                        push(pow(second_operand, first_operand));
                } else
                    printf("\nError : Function unsupported : %s", input_string);
                break;
            case ARITH:
                first_operand = pop();
                second_operand = pop(); 
                switch(get_operation_or_stack_command(key_character)) {
                    case '+':
                        push(first_operand + second_operand);
                        break;
                    case '*':
                        push(first_operand * second_operand);
                        break;
                    case '-':
                        push(second_operand - first_operand);
                        break;
                    case '/':
                        if (first_operand != 0)
                            push(second_operand / first_operand);
                        else
                            printf("Error : 0 divisor\n");
                        break;
                    case '%':
                        if (first_operand != 0)
                            push((int)second_operand % (int)first_operand);
                        else
                            printf("Error : 0 divisor\n");
                        break;
                }
                break;
            case STACK:
                switch(get_operation_or_stack_command(key_character)) {
                    case PRINT:
                        printf("\t%g\n", top());
                        break;
                    case DUPLICATE: 
                        push(top());
                        break;
                    case SWITCH:
                        first_operand = pop();
                        second_operand = pop();
                        push(first_operand);
                        push(second_operand);
                        break;
                    case CLEAR:
                        clear_stack();
                        break;
                }
                break;
            case '\n':
                printf("\t%g\n", pop());
                break;
            default:
                printf("Error : Unknown command %s\n", input_string);
                break;
        }
    } while (type != EOF);

    return 0;
}
