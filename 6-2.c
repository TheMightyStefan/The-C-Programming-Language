#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000
#define BUFFER_SIZE 100000
#define KEY_WORDS 18
#define MAX_LENGTH 10000
#define LETTERS 3

int buffer_index = 0;
char buffer[BUFFER_SIZE];

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
        } else 
            for ( ; !isspace(character) && character != EOF; character = get_character());

        if (character != '\"' && character != '\n' && character != '/')
            unget_character(character);
    
        *word_ptr = '\0';
        return character; 
    }

    for ( ; --limit > 0; ) {
        char check_character = get_character();

        if (!isalnum(check_character)) {
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

int key_word(char string[MAX_LENGTH]) {
    char key_word[KEY_WORDS][MAX_LENGTH] = {
        "int",
        "char",
        "if",
        "while",
        "for",
        "void",
        "struct",
        "sizeof",
        "return",
        "NULL",
        "else",
        "switch",
        "break",
        "float",
        "double",
        "extern",
        "register",
        "const"
    };

    for (int index = 0; index < KEY_WORDS; index++)
        if (strcmp(string, key_word[index]) == 0)
            return 1;

    return 0;
}

char group_list[MAX_WORDS][MAX_LENGTH];
int group_index = 0;

char *get_group(char string[MAX_LENGTH]) {
    char *group;
    group = (char *) malloc (sizeof(char) * MAX_LENGTH);

    for (int index = 0; index < LETTERS; index++)
        group[index] = string[index];

    return group;
}

void add_group(char string[MAX_LENGTH]) {
    char *new_group;
    int found = 0;

    new_group = get_group(string);

    for (int index = 0; index < group_index; index++)
        if (strcmp(group_list[index], new_group) == 0)
            found = 1;

    if (!found)
        strcpy(group_list[group_index++], new_group);
}

void addtree(struct tnode **ptr, char *word) {
    if (*ptr == NULL) {
        *ptr = talloc();
        (*ptr)->word = string_duplicate(word);
        (*ptr)->count = 1;
        (*ptr)->left = (*ptr)->right = NULL;
    } else if (strcmp(word, (*ptr)->word) == 0)
        (*ptr)->count++;
    else if (strcmp(word, (*ptr)->word) < 0)
        addtree(&(*ptr)->left, word);
    else
        addtree(&(*ptr)->right, word);
}
 
void treeprint(struct tnode *ptr, char group[MAX_LENGTH]) {
    if (ptr != NULL) {
        treeprint(ptr->left, group);

        if (strcmp(get_group(ptr->word), group) == 0)
            printf("%s\n", ptr->word);

        treeprint(ptr->right, group);
    }
}

void clear_string(char string[MAX_LENGTH]) {
    for (int index = strlen(string); index > 0; index--)
        string[index] = 0;
}

int main() {
    struct tnode *root;
    char word[MAX_WORDS];

    root = NULL;
    while (get_word(word, MAX_WORDS) != EOF)
        if (isalpha(word[0])) {
            if (!key_word(word)) {
                add_group(word);
                addtree(&root, word);
            }
        
            clear_string(word);
        }
  
    printf("\n");
  
    for (int index = 0; index < group_index; index++) {
        treeprint(root, group_list[index]);

        printf("\n");
    }

    return 0;
}

