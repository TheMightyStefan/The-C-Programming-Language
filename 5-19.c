#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_TOKEN 100
#define BUFFER_SIZE 100

enum { NAME, PARENS, BRACKETS };
enum { YES, NO };

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

int token_skip = NO;

void print_error(char *error) {
    printf("%s", error);
    
    token_skip = YES;
}
    
int token_type;
char token[MAX_TOKEN];
char name[MAX_TOKEN];
char datatype[MAX_TOKEN];
char out[1000];

int get_token(void) {
    int character = get_character();
    char *ptr = token;

    if (token_skip == YES) {
        token_skip = NO;

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

int get_next_token() {
    int next_token = get_token();

    token_skip = YES;

    return next_token;
}

int main() {
    int type;
    char temp[MAX_TOKEN];
    
    while (get_token() != EOF) {
        strcpy(out, token);
        while ((type = get_token()) != '\n')
            if (type == PARENS || type == BRACKETS)
                strcat(out, token);
            else if (type == '*') {
                type = get_next_token();

                if (type == PARENS || type == BRACKETS)
                    sprintf(temp, "(*%s)", out);
                else
                    sprintf(temp, "*%s", out);
                strcpy(out, temp);
            } else if (type == NAME) {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            } else
                printf("Ivalid output at %s\n, token");
        printf("%s\n", out);
    }

    return 0;
} 
