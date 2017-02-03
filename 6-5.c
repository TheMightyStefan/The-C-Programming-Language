#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define HASH_SIZE 101

struct table_list {
    struct table_list *next;
    char *name;
    char *definition;
};

static struct table_list *hash_tab[HASH_SIZE];

unsigned hash(char *string) {
    unsigned hash_value = 0;

    for ( ; *string != '\0'; string++)
        hash_value = *string + 31 * hash_value;

    return hash_value % HASH_SIZE;
}

struct table_list *lookup(char *string) {
    struct table_list *table_index = hash_tab[hash(string)];

    for ( ; table_index != NULL; table_index = table_index->next) {
        if (strcmp(string, table_index->name) == 0)
            return table_index;

        table_index = hash_tab[hash(string)];
    }

    return NULL;
}

char *string_duplicate(char *string) {
    char *ptr;

    ptr = (char *) malloc(strlen(string) + 1);

    if (ptr != NULL)
        strcpy(ptr, string);

    return ptr;
}

struct table_list *install(char *name, char *definition) {
    struct table_list *table_tool;
    unsigned hash_value;

    table_tool = lookup(name);

    if (table_tool == NULL) {
        table_tool = (struct table_list *) malloc (sizeof(*table_tool));

        table_tool->name = string_duplicate(name);

        if (table_tool == NULL || table_tool->name == NULL)
            return NULL;

        hash_value = hash(name);
        table_tool->next = hash_tab[hash_value];
        hash_tab[hash_value] = table_tool;
    } else
        free((void *) table_tool->definition);

    table_tool->definition = string_duplicate(definition);

    if (table_tool->definition == NULL)
        return NULL;

    return table_tool;
}

struct table_list *undef(char *name) {
    struct table_list *found;

    found = lookup(name);

    if (found == NULL)
        return NULL;
    else {
        if (found->next != NULL) {
            found->next = found->next->next;
            found = found->next;
        } else {
            hash_tab[hash(name)] = NULL;
            free((void *) found);
        }
    }

    return found;
}

int main() {
    install("key_1", "value_1");
    install("key_2", "value_2");
    install("key_3", "value_3"); 
    install("key_4", "value_4"); 
    install("key_5", "value_5"); 

    undef("key_1");
    printf("Undef key_1 ....\n\n");

    undef("key_4"); 
    printf("Undef key_4 ....\n\n");

    char *keys[5] = {
        "key_1",
        "key_2",
        "key_3",
        "key_4",
        "key_5",
    };

    struct table_list *search;

    for (int index = 0; index < 5; index++) {
        search = lookup(keys[index]);

        if (search == NULL)
            printf("%s not found\n\n", keys[index]);
        else
            printf("%s->%s\n\n", search->name, search->definition);
    }
 
    return 0;
} 
