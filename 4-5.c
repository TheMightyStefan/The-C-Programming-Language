#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

// Command to print the top element of the stack
#define PRINT '#'

// Comand to swap the top two elements
#define SWAP '$'

// Command to duplicate the top element of the stack
#define DUPLICATE '@'

// Command to clear the stack
#define CLEAR '?'

// Command to switch the top elements of the stack
#define SWITCH '~'

#define MATH '&'
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

        printf("%s\n", input_string);

        if (character != EOF)
            unget_character(character);
    
        return MATH;
    }
    // Return the operator, except in case of '-'
    if (!isdigit(character) && !isalpha(character) && character != '.' && character != '-')
        return character;

    if (character != '-') {
        input_string[0] = character;
        get_digits(input_string);
        return NUMBER;
    } else if (stack_index < 2) {
        input_string[0] = '-';
        get_digits(input_string);
        return NUMBER;
    } else {
        return '-';
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

void clear_stack() {
    stack_index = 0;
}

void handle_math_function(char string[]) {
    double operand;

    if (strcmp(string, "sin") == 0) 
        push(sin(pop()));
    else if (strcmp(string, "cos") == 0)
        push(cos(pop()));
    else if (strcmp(string, "exp") == 0)
        push(exp(pop()));
    else if (strcmp(string, "pow") == 0) {
        operand = pop();
        push(pow(pop(), operand));
    } else 
        printf("Unsupported function : %s\n", string);
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
                handle_math_function(input_string);
                break;
            // Do the requested operations
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                second_operand = pop();
                first_operand = pop();
                push(first_operand - second_operand);
                break;
            case '/':
                second_operand = pop();
                first_operand = pop();
                if (second_operand != 0)
                    push(first_operand / second_operand);
                else
                    printf("Error : 0 divisor\n");
                break;
            case '%':
                second_operand = pop();
                first_operand = pop();
                if (second_operand != 0)
                    push((int)first_operand % (int)second_operand);
                else
                    printf("Error : 0 divisor\n");
                break;
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
            // Print output
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
