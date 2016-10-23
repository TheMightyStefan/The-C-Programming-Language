#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

int stack_index = 0;
double stack[MAX_STACK_SIZE];

void error(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

// Function for pushing into stack
void push(double new_stack_number) {
    if (stack_index < MAX_STACK_SIZE)
        stack[stack_index++] = new_stack_number;
    else
        error("Error : Stack full\n");
}

// Function for poping from stack
double pop() {
    if (stack_index > 0) 
        return stack[--stack_index];
    else {
        error("Error : Stack empty\n");
        return 0;
    }
}
   
int main(int argc, char **argv) {
    int temp = 0;

    for (int arg_index = 1; arg_index < argc; arg_index++)
        switch (argv[arg_index][0]) {
            case '\0':
                error("Empty command line argument");
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                push(atof(argv[arg_index]));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                temp = pop();
                push(pop() - temp);
                break;
            case 'x':
                push(pop() * pop());
                break;
            case '/':
                temp = pop();
                push(pop() / temp);
                break;
            default:
                error("Unknown operator");
                break;
        }

    printf("%g\n", pop());
    return 0;
}
