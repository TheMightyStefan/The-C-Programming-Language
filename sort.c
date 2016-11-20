#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NUMBER_OF_STRINGS 40
#define MAX_STRING_LENGTH 20

void swap(char **str_1, char **str_2) {
    char *temp = *str_1;

    *str_1 = *str_2;
    *str_2 = temp;
}

void sort(char str[][MAX_STRING_LENGTH], int str_nr) {
    for (int index_1 = 0; index_1 < str_nr; index_1++)
        for (int index_2 = 0; index_2 < str_nr - 1; index_2++)
            if (strcmp(str[index_2], str[index_2 + 1]) > 0)
              swap(str[index_2], str[index_2 + 1]);
}

int main() {
    char str[MAX_NUMBER_OF_STRINGS][MAX_STRING_LENGTH];
    int index = -1;
    int str_index = 0;

    do {
        do
          str[str_index][++index] = getchar();
        while (str[str_index][index] != '\n' && str[str_index][index] != EOF);
    
        if (str[str_index][index] == '\n') {
            str[str_index][index] = '\0';
 
            str_index++;
            index = 0;
            str[str_index][index] = getchar();
        }

        if (str[str_index][index] == EOF)
            str[str_index][index] = '\0';
        
    } while (str[str_index][index] != '\0');
  
    sort(str, str_index);

    for (int index = 0; index <= str_index; index++)
        printf("\n%s", str[index]);

    return 0;
} 
