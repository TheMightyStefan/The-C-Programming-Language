#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_TOKEN 100
#define BUFFER_SIZE 100

enum { NAME, PARENS, BRACKETS };
enum { NO_ERROR, ERROR };

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

int token_error = NO_ERROR;

void print_error(char *error) {
    printf("%s", error);
    
    token_error = ERROR;
}
    
int token_type;
char token[MAX_TOKEN];
char name[MAX_TOKEN];
char datatype[MAX_TOKEN];
char out[1000];

int get_token(void) {
    int character = get_character();
    char *ptr = token;

    if (token_error == ERROR) {
        token_error = NO_ERROR;

        unget_character(character);

        return token_type;
    }

    while (character == ' ' || character == '\t')
        character = get_character();

    if (character == '(') {
        character = getchar();

        if (character == ')') {
            strcpy(token, "()");
            
            return token_type = PARENS;
        } else {
            unget_character(character);
    
            return token_type = '(';
        } 
     } else if (character == '[') {
        for (*ptr++ = character; (*ptr++ = get_character()) != ']'; );

        *ptr = '\0';

        return token_type = BRACKETS;
    } else if (isalpha(character)) {
        for (*ptr++ = character; isalnum(character = get_character()); )
            *ptr++ = character;

        *ptr = '\0';
        unget_character(character); 
        return token_type = NAME;
    } else
        return token_type = character;
}

void declarator(void);

void direct_declarator(void) {
    int type;

    if (token_type == '(') {
        declarator();

        if (token_type != ')')
            print_error("Error : Missing ')'\n");
    } else if (token_type == NAME)
        strcpy(name, token);
    else
        print_error("Error : Expected name or (declarator)\n");

    type = get_token();

    while (type == PARENS || type == BRACKETS) {
        if (type == PARENS)
            strcat(out, " function returning");
        else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }

        type = get_token();
    }
}

void declarator(void) {
    int ns = 0;

    for ( ; get_token() == '*'; )
        ns++;

    direct_declarator();

    while (ns-- > 0)
        strcat(out, " pointer to");
}

int main() {
    while (get_token() != EOF) {
        strcpy(datatype, token);
        out[0] = '\0';
        declarator();
        if (token_type != '\n')
            print_error("Syntax Error\n");
        printf("%s : %s %s\n", name, out, datatype);
    }

    return 0;
}
