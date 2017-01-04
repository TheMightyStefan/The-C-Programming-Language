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

#define QUALIFIERS 5

char qualifier[QUALIFIERS][MAX_TOKEN] = {
    "static",
    "const",
    "register",
    "extern",
};

#define DATA_TYPES 5

char data_type[DATA_TYPES][MAX_TOKEN] = {
    "int",
    "void",
    "char",
    "float",
};

int qualifier_checker(char string[MAX_TOKEN]) {
    for (int index = 0; index < QUALIFIERS; index++)
        if (strcmp(string, qualifier[index]) == 0)
            return 1;

    return 0;
}

int data_type_checker(char string[MAX_TOKEN]) {
    for (int index = 0; index < DATA_TYPES; index++)
        if (strcmp(string, data_type[index]) == 0)
            return 1;

    return 0;
}
 
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
    } else if (isalpha(character) || character == '_') {
        for (*ptr++ = character; isalnum(character = get_character()) || character == '_'; )
            *ptr++ = character;

        *ptr = '\0';
        unget_character(character); 
        return token_type = NAME;
    } else
        return token_type = character;
}

void declarator(void);

void specification_declarator(void) {
    char temp[MAX_TOKEN];

    temp[0] = '\0';
    get_token();

    do {
        if (token_type != NAME) {
            token_error = ERROR;
            declarator();
        } else if (data_type_checker(token)) {
            strcat(temp, " ");
            strcat(temp, token);
            get_token();
        } else if (qualifier_checker(token)) {
            strcat(temp, " ");
            strcat(temp, token);
            get_token();
        } else
            print_error("Unknown parameter type\n");
    } while (token_type != ',' && token_type != ')');

    strcat(out, temp);

    if (token_type == ',')
        strcat(out, ",");
}  

void parameter_declarator(void) {
    do {
        specification_declarator();
    } while (token_type == ',');

    if (token_type != ')')
        print_error("Missing ) in function\n");
}

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

    while (type == PARENS || type == BRACKETS || type == '(') {
        if (type == PARENS)
            strcat(out, " function returning");
        else if (type == '(') {
            strcat(out, " function expecting");
            parameter_declarator();
            strcat(out, " and returning");     
        } else {
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
        if (qualifier_checker(token)) {
            strcpy(datatype, token);

            get_token();

            strcat(datatype, " ");
            strcat(datatype, token);
        } else
            strcpy(datatype, token);
        
        out[0] = '\0'; 

        declarator();

        if (token_type != '\n')
            print_error("Syntax Error\n");

        printf("%s : %s %s\n", name, out, datatype);
    }

    return 0;
}
