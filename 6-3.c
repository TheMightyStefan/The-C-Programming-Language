#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100
#define BUFFER_SIZE 100
#define MAX_LENGTH 100
#define NOISE_WORDS 2

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

char get_word(char *word, int limit, int *line_number) {
    char *word_ptr = word;
    char character;

    while (isspace(character = get_character()))
        if (character == '\n') {
           *line_number = *line_number + 1;
        }

    if (character != EOF)
        *word_ptr++ = character;

    if (!isalpha(character)) {
        *word_ptr = '\0';
        return character; 
    }

    for ( ; --limit > 0; word_ptr++)
        if (!isalnum(*word_ptr = get_character())) {
            if (!isspace(*word_ptr)) {
                unget_character(*word_ptr);
                return (*word_ptr);      
            } else {
                if (character == '\n') {
                    *line_number = *line_number + 1;
                }

                unget_character(*word_ptr);
                break;
            }
        }

    *word_ptr = '\0';
    return word[0];
}
struct tnode {
    char *word;
    int line_numbers[MAX_WORDS];
    int line_index;
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

int noise_words_checker(char string[MAX_LENGTH]) {
    char noise_word[NOISE_WORDS][MAX_LENGTH] = {
        "the",
        "and"
    };

    for (int index = 0; index < NOISE_WORDS; index++)
        if (strcmp(string, noise_word[index]) == 0)
            return 1;

    return 0;
}

void add_line(struct tnode **ptr, int line_number) {
    if ((*ptr)->line_index == 0) {
        (*ptr)->line_numbers[0] = line_number;
        (*ptr)->line_index++;
    } else {
        int found = 0;

        for (int index = 0; index < (*ptr)->line_index; index++)
            if ((*ptr)->line_numbers[index] == line_number)
                found = 1;

        if (!found) {
            (*ptr)->line_numbers[(*ptr)->line_index] = line_number;
            (*ptr)->line_index++;
        }
    }
}        

void addtree(struct tnode **ptr, char *word, int line_number) {
    if (*ptr == NULL) {
        *ptr = talloc();
        (*ptr)->word = string_duplicate(word);
        add_line(ptr, line_number);
        (*ptr)->left = (*ptr)->right = NULL;
    } else if (strcmp(word, (*ptr)->word) == 0) 
        add_line(ptr, line_number);
    else if (strcmp(word, (*ptr)->word) < 0) 
        addtree(&(*ptr)->left, word, line_number);
    else
        addtree(&(*ptr)->right, word, line_number);
}
 
void treeprint(struct tnode *ptr) {
    if (ptr != NULL) {
        treeprint(ptr->left);

        printf("%s ", ptr->word);
        
        if (ptr->line_numbers[0])
            for (int index = 0; index < ptr->line_index; index++)
                printf("%d ", ptr->line_numbers[index]);

        printf("\n");

        treeprint(ptr->right);
    }
}

int main() {
    struct tnode *root;
    char word[MAX_WORDS];
    int line_number = 1;

    root = NULL;
    while (get_word(word, MAX_WORDS, &line_number) != EOF) {
        if (isalpha(word[0]))
            if (!noise_words_checker(word))
                addtree(&root, word, line_number);
    }

    printf("\n");
 
    treeprint(root);

    return 0;
}

