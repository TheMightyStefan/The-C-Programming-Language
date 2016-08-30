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

void push(double new_stack_number) {
    if (stack_index < MAX_STACK_SIZE)
        stack[stack_index++] = new_stack_number;
    else
        printf("Error : Stack full\n");
}
    
double pop() { 
    if (stack_index > 0) 
        return stack[--stack_index];
    else {
        printf("Error : Stack empty\n");
        return 0;
    }
}

int get_character() {
    return (buffer_index > 0) ? buffer[--buffer_index] : getchar();
}

void unget_character(int character) {
    if (buffer_index >= BUFFER_SIZE)
        printf("Ungetch : Too many characters\n");
    else
        buffer[buffer_index++] = character;
}

int get_operators(char input_string[]) {
    int string_index = 0;
    int character;

    while ((input_string[0] = character = get_character()) == ' ' || character == '\t');

    input_string[1] = '\0';

    if (!isdigit(character) && character != '.' && character != '-')
        return character;

    if (character != '-') {
    	if (isdigit(character))
        	while (isdigit(input_string[++string_index] = character = get_character()));

    	if (character == '.')
        	while (isdigit(input_string[++string_index] = character = get_character()));
    
    	input_string[string_index] = '\0';

    	if (character != EOF)
        	unget_character(character);
    
    	return NUMBER;
   
   } else {
	   int temp_character;
	   if (isdigit(temp_character = get_character())) {
		input_string[++string_index] = temp_character;
		input_string[0] = '-';

		while (isdigit(input_string[++string_index] = character = get_character()));

		if (character == '.')
			while (isdigit(input_string[++string_index] = character = get_character()));

		input_string[string_index] = '\0';

		if (character != EOF) {
			unget_character(character);
		}
		return NUMBER;
	   } else {
		unget_character(temp_character);
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
            case NUMBER:
                push(atof(input_string));
                break;
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
		printf("\t%g\n", pop());
                break;
            default:
                printf("Error : Unknown command %s\n", input_string);
                break;
        }
    }

    return 0;
}            
        
