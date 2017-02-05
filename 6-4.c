#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 100
#define BUFFER_SIZE 100

int buffer_index = 0;
char buffer[100];

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
        if (character == '"')
            for (character = get_character(); character != '"'; character = get_character());
        else if (character == '\"')
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

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *string_duplicate(char *string) {
    char *ptr;

    ptr = (char *) malloc(strlen(string) + 1);

    if (ptr != NULL)
        strcpy(ptr, string);

    return ptr;
}

int addtree(struct tnode **ptr, char *word) {
    int max_count = 1;

    if (*ptr == NULL) {
        *ptr = talloc();
        (*ptr)->word = string_duplicate(word);
        (*ptr)->count = 1;
        (*ptr)->left = (*ptr)->right = NULL;
    } else if (strcmp(word, (*ptr)->word) == 0) {
        (*ptr)->count++;

        if ((*ptr)->count > max_count)
            max_count = (*ptr)->count;
    } else if (strcmp(word, (*ptr)->word) < 0) {
        int count = addtree(&(*ptr)->left, word);

        if (count > max_count)
            max_count = count;
    } else {
        int count = addtree(&(*ptr)->right, word);

        if (count > max_count)
            max_count = count;
    }

    return max_count;
}
 
void treeprint(struct tnode *ptr, int count) {
    if (ptr != NULL) {
        treeprint(ptr->left, count);

        if (ptr->count == count)
            printf("%4d %s\n", ptr->count, ptr->word);

        treeprint(ptr->right, count);
    }
}

void clear_string(char string[MAX_LENGTH]) {
    for (int index = strlen(string); index > 0; index--)
        string[index] = 0;
}

int main() {
    struct tnode *root;
    char word[MAX_WORDS];
    int max_count;


    root = NULL;
    while (get_word(word, MAX_WORDS) != EOF) {
        if (isalpha(word[0])) {
            int count = addtree(&root, word);

            if (count > max_count)
                max_count = count;
        }

        clear_string(word);
    }

    while (max_count) {
        treeprint(root, max_count);
        max_count--;
    }

    return 0;
}

