#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORDS 10000
#define BUFFER_SIZE 1000000
#define MAX_LENGTH 1000000

char buffer[100];
int buffer_index = 0;

void unget_character(char character) {
    if (buffer_index >= BUFFER_SIZE)
        fprintf(stderr, "Ungetch : Too many characters\n");
    else
        buffer[buffer_index++] = character;
}

int get_character() {
    if (buffer_index > 0)
        return buffer[--buffer_index];
    else
        return getchar();
}

char get_to(char destination) {
    char character = get_character();

    for ( ; character != destination; character = get_character());

    return character;
}

char skip(char target) {
    char character = target;

    if (character == '#')
        character = get_to('\n');
    else if (character == '\"') {
        char temp_character = get_character();

        if (temp_character != '\'')
            character = get_to('\"');
        else 
            unget_character(temp_character);
    } else if (character == '/') {
        char temp_character = get_character();
    
        if (temp_character == '/')
            character = get_to('\n');
        else if (temp_character == '*') {
            character = get_to('*');

            if (character == '/')
                character = get_character();
        } else 
            unget_character(temp_character);
    }

    return character;
}

int get_word(char *word, int limit) {   
    char *word_ptr = word;
    char character = get_character();
 
    while (isspace(character))
        character = get_character();

    if (character != EOF && isalnum(character))
        (*word_ptr++) = character;

    if (!isalpha(character)) {
        character = skip(character);

        *word_ptr = '\0';
        return character; 
    }

    while (--limit > 0) {
        char check_character = get_character();

        if (!isalnum(check_character) && check_character != '_') {
            if (!isspace(check_character)) {
                unget_character(check_character);
                return check_character;
            } else {
                unget_character(check_character);
                limit = -1;
            }
        } else
            *word_ptr++ = check_character;
    }
    
    *word_ptr = '\0';
    return word[0];
}

struct word_counter {
    char *word;
    int count;
}; 

struct word_counter key_words[] = {
    { "auto", 0 },
    { "break", 0},
    { "case", 0 },
    { "char", 0 },
    { "const", 0 },
    { "continue" , 0 },
    { "default", 0 },
    { "define", 0 },
    { "do" , 0 },
    { "double", 0 },
    { "else", 0 },
    { "enum", 0 },
    { "extern", 0 },
    { "float", 0 },
    { "for", 0 },
    { "goto", 0 },
    { "if", 0 },
    { "int", 0 },
    { "long", 0 },
    { "register", 0 },
    { "return", 0 },
    { "short", 0 },
    { "signed", 0 },
    { "sizeof", 0 },
    { "static", 0 },
    { "struct", 0 },
    { "switch", 0 },
    { "typedef", 0 },
    { "union", 0 },
    { "unsigned", 0 },
    { "void", 0 },
    { "volatile", 0 },
    { "while" , 0}
};

int binary_search(char *word, struct word_counter table[], int n) {
    int low = 0;
    int high = n - 1;
    int mid = 0;
 
    while (low <= high) {
        mid = (low + high) / 2;
        if (strcmp(word, table[mid].word) < 0)
            high = mid - 1;
        else if (strcmp(word, table[mid].word) > 0)
            low = mid + 1;
        else
            return mid;
    }
    
    return -1;
}

void clear_string(char string[MAX_LENGTH]) {
    for (int index = strlen(string) - 1; index >= 0; index--)
        string[index] = 0;
}

#define NKEYS (sizeof(key_words) / sizeof(struct word_counter))

int main() {
    int n;
    char word[MAXWORDS];

    while (get_word(word, MAXWORDS) != EOF) {
        if (isalpha(word[0])) {
            if ((n = binary_search(word, key_words, NKEYS)) >= 0)
                key_words[n].count++;

	    clear_string(word);
        }
    }

    for (n = 0; n < NKEYS; n++)
        if (key_words[n].count > 0)
            printf("%4d %s\n", key_words[n].count, key_words[n].word);

    return 0;
}
