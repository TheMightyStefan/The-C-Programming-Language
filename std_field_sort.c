#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_NUMBER_OF_STRINGS 40
#define MAX_STRING_LENGTH 50
#define MAX_FIELDS_NUMBER 40
#define MAX_ARGS 30

#define GOT_THE_LINE 1
#define END_OF_INPUT 0

#define SWAPPED 1
#define NOT_SWAPPED 0

#define FOLD 'F'
#define NORMAL 'N'
#define BACKWARDS 'R'
#define NUMERICAL 'n'
#define DIRECTORY 'D'

struct swapped {
    char str_1[MAX_STRING_LENGTH];
    char str_2[MAX_STRING_LENGTH];
};

struct swapped swapped[MAX_FIELDS_NUMBER];

int getnumber(char str[], int index) {
    for ( ; str[index] != '\0' && !isdigit(str[index]); index++);

    int number = 0;

    while (isdigit(str[index]))
        number = 10 * number + (str[index++] - '0');

    return number;
}

void swap(char str_1[], char str_2[]) {
    char temp[MAX_STRING_LENGTH];

    strcpy(temp, str_1);
    strcpy(str_1, str_2);
    strcpy(str_2, temp);
}

int getline(char str[]) {
    int index = -1;    

    do
        str[++index] = getchar();
    while (str[index] != EOF && str[index] != '\n' && index < MAX_STRING_LENGTH);

    if (str[index] == EOF) {
        str[index] = '\0';
        return END_OF_INPUT;
    } else if (str[index] == '\n')
        str[index] = '\0';
    else
        printf("GETLINE ERROR\n");

    return GOT_THE_LINE;
}

void create_fields(char str[][MAX_STRING_LENGTH], char field[][MAX_FIELDS_NUMBER][MAX_STRING_LENGTH], int str_nr) {
    int str_index = 0;
    int field_index = 0;
    int field_str_index = 0;

    while (str_index < str_nr) {
        int index = 0;

        for ( ; isspace(str[str_index][index]); index++);

        while (index < strlen(str[str_index])) {
            if (!isspace(str[str_index][index]))
                field[str_index][field_str_index][field_index++] = str[str_index][index++];
            else if (isspace(str[str_index][index])) {
                field[str_index][field_str_index][field_index] = '\0';
                field_index = 0;
                field_str_index++;
                index++;
        }

            if (str[str_index][index] == '\0') {
                field[str_index][field_str_index][field_index] = '\0';
                field_index = 0;
                field_str_index = 0;
                str_index++;
                index = 0;
            }
        }
    }    
}

int swap_checker(char str_1[], char str_2[], int swap_index) {
    for (int index = 0; index < swap_index; index++)
        if (strcmp(swapped[index].str_1, str_1) == 0 && strcmp(swapped[index].str_2, str_2) == 0)
            return SWAPPED;
        else if (strcmp(swapped[index].str_1, str_2) == 0 && strcmp(swapped[index].str_2, str_1) == 0)
            return SWAPPED;

    return NOT_SWAPPED;
}
 
void sort(char str[][MAX_STRING_LENGTH], int str_nr, int field_number) {
    char field[MAX_NUMBER_OF_STRINGS][MAX_FIELDS_NUMBER][MAX_STRING_LENGTH]; 
    int swap_index = 0;

    create_fields(str, field, str_nr);

    printf("\n");

    for (int index_1 = 0; index_1 < str_nr; index_1++)
        for (int index_2 = 0; index_2 < str_nr - 1; index_2++) {
            printf("%s\n%s\n", field[index_2][field_number], field[index_2 + 1][field_number]);
            printf("\n");

            if (strcmp(field[index_2][field_number], field[index_2 + 1][field_number]) > 0) {
                if (swap_index == 0) {
                    strcpy(swapped[swap_index].str_1, field[index_2][swap_index]);
                    strcpy(swapped[swap_index].str_2, field[index_2 + 1][swap_index]); 
      
                    swap_index = 1;
                    
                    swap(str[index_2], str[index_2 + 1]);
                    swap(field[index_2][field_number], field[index_2 + 1][field_number]);

                    printf("SWAPPED : %s --- %s\n", field[index_2][field_number], field[index_2 + 1][field_number]);
                } else if (swap_checker(field[index_2][field_number], field[index_2 + 1][field_number], swap_index) == NOT_SWAPPED) {
                    printf("SWAPPED : %s --- %s\n", field[index_2][field_number], field[index_2 + 1][field_number]);
                 
                    strcpy(swapped[swap_index].str_1, field[index_2][field_number]);
                    strcpy(swapped[swap_index].str_2, field[index_2 + 1][field_number]); 
 
                    swap_index++;

                    swap(str[index_2], str[index_2 + 1]);
                    swap(field[index_2][field_number], field[index_2 + 1][field_number]); 
               }
            } 
        }
}

int main(int argc, char *argv[]) {
    char str[MAX_NUMBER_OF_STRINGS][MAX_STRING_LENGTH];
    int str_index = -1;

    do
        str_index++;
    while (getline(str[str_index]) == GOT_THE_LINE && str_index < MAX_NUMBER_OF_STRINGS);

    sort(str, str_index, 1);

    printf("\n");
 
    for (int index = 0; index < str_index; index++)
        printf("%s\n", str[index]);

    return 0;
} 
