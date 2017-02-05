#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define NKEYS (sizeof(keytab) / sizeof(struct key))
#define MAXWORDS 10000
#define BUFFER_SIZE 1000000
#define MAX_LENGTH 1000000

char buffer[100];
int buffer_index = 0;

void unget_character(int character) {
    if (buffer_index >= BUFFER_SIZE)
        printf("\nUngetch : Too many characters");
    else
        buffer[buffer_index++] = character;
}

int get_character() {
    if (buffer_index > 0)
        return buffer[--buffer_index];
    else
        return getchar();
}

int get_word(char *word, int limit) {   
    char *word_ptr = word;
    char character;
    char temp_character;
 
    while (isspace(character = get_character()));

    if (character != EOF && isalnum(character))
        *word_ptr++ = character;

    if (!isalpha(character)) {
        if (character == '\"')
            for (character = get_character(); character != '\"'; character = get_character());
        else if (character == '#')
            for (character = get_character(); character != '\n'; character = get_character());
        else if (character == '/') {
            if ((character = get_character()) == '/')
                for (character = get_character(); character != '\n'; character = get_character());
            else if (character == '*') {
                for (character = get_character(), temp_character = get_character(); character != '*' && temp_character != '/'; character = get_character(), temp_character = get_character())
                    unget_character(temp_character);
            } else
                unget_character(character);
        } else if (character != '(' && character != '*' && character != '[' && character != '!' && character != '&' && character != '-' && character != '+') 
            for ( ; !isspace(character) && character != EOF; character = get_character());

        *word_ptr = '\0';
        return character; 
    }

    for ( ; --limit > 0; ) {
        char check_character = get_character();

        if (!isalnum(check_character) && check_character != '_') {
            if (!isspace(check_character)) {
                unget_character(check_character);
                return check_character;
            } else {
                unget_character(check_character);
                break;
            }
        } else
            *word_ptr++ = check_character;
    }
    
    *word_ptr = '\0';
    return word[0];
}

struct key {
    char *word;
    int count;
} keytab[] = {
    { "auto", 0 },
    { "break", 0},
    { "case", 0 },
    { "char", 0 },
    { "const", 0 },
    { "continue" , 0 },
    // ........... //
    { "default", 0 },
    { "define", 0 },
    { "if", 0 },
    { "int", 0 },
    { "include", 0 }, 
    { "unsigned", 0 },
    { "while" , 0},
};

int binary_search(char *word, struct key tab[], int n) {
    int low = 0;
    int high = n - 1;
    int mid;
 
    while (low <= high) {
        mid = (low + high) / 2;
        if (strcmp(word, tab[mid].word) < 0)
            high = mid - 1;
        else if (strcmp(word, tab[mid].word) > 0)
            low = mid + 1;
        else
            return mid;
    }
    
    return -1;
}

void clear_string(char string[MAX_LENGTH]) {
    for (int index = strlen(string); index > 0; index--)
        string[index] = 0;
}

int main() {
    int n;
    char word[MAXWORDS];

    while (get_word(word, MAXWORDS) != EOF) {
        if (isalpha(word[0])) {
            if ((n = binary_search(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;

	    clear_string(word);
        }
    }
    
    for (n = 0; n < NKEYS; n++)
        if (keytab[n].count > 0)
            printf("%4d %s\n", keytab[n].count, keytab[n].word);

    return 0;
}
