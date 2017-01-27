#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100
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

    if (character != EOF)
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
        } else 
            for ( ; !isspace(character) && character != EOF; character = get_character());

        if (character != '\"' && character != '\n' && character != '/')
            unget_character(character);
    
        *word_ptr = '\0';
        return character; 
    }

    for ( ; --limit > 0; word_ptr++)
        if (!isalnum(*word_ptr = get_character())) {
            if (!isspace(*word_ptr)) {
                unget_character(*word_ptr);
                return (*word_ptr);      
            } else {
                unget_character(*word_ptr);
                break;
            }
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

int max_count = 1;

struct tnode *addtree(struct tnode *ptr, char *word) {
    if (ptr == NULL) {
        ptr = talloc();
        ptr->word = string_duplicate(word);
        ptr->count = 1;
        ptr->left = ptr->right = NULL;
    } else if (strcmp(word, ptr->word) == 0) {
        ptr->count++;

        if (ptr->count > max_count)
            max_count = ptr->count;
    } else if (strcmp(word, ptr->word) < 0)
        ptr->left = addtree(ptr->left, word);
    else
        ptr->right = addtree(ptr->right, word);
    
    return ptr;
}
 
void treeprint(struct tnode *ptr, int count) {
    if (ptr != NULL) {
        treeprint(ptr->left, count);

        if (ptr->count == count)
            printf("%4d %s\n", ptr->count, ptr->word);

        treeprint(ptr->right, count);
    }
}

int main() {
    struct tnode *root;
    char word[MAX_WORDS];

    root = NULL;
    while (get_word(word, MAX_WORDS) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    
    while (max_count) {
        treeprint(root, max_count);
        max_count--;
    }

    return 0;
}

