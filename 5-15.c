#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUMBER_OF_STRINGS 40
#define MAX_STRING_LENGTH 20

#define GOT_THE_LINE 1
#define END_OF_INPUT 0

#define FOLD 'F'
#define NORMAL 'N'
#define BACKWARDS 'R'
#define NUMERICAL 'n'

int getnumber(char str[], int index) {
    for ( ; str[index] != '\0' && !isdigit(str[index]); index++);

    int number = 0;

    while (isdigit(str[index]))
        number = 10 * number + (str[index++] - '0');

    return number;
}

void swap(char **str_1, char **str_2) {
    char *temp;

    temp = *str_1;
    *str_1 = *str_2;
    *str_2 = temp;
}

void create_lower(char str[], char temp[]) {
    for (int index = 0; str[index] != '\0'; index++) {
            if (isupper(str[index]))
                temp[index] = str[index] + 32;
            else
                temp[index] = str[index];
    }
}       
    
void sort(char str[][MAX_STRING_LENGTH], int str_nr, char arg) {    
    if (arg == BACKWARDS)
        for (int index = 0; index < str_nr / 2; index++)
            swap(str[index], str[str_nr - index - 1]);

    for (int index_1 = 0; index_1 < str_nr; index_1++)
         for (int index_2 = 0; index_2 < str_nr - 1; index_2++) {
            if (arg == NORMAL) {
                if (strcmp(str[index_2], str[index_2 + 1]) > 0)
                    swap(str[index_2], str[index_2 + 1]);
            } else if (arg == FOLD) {
                char temp[2][MAX_STRING_LENGTH];

                create_lower(str[index_2], temp[0]);
                create_lower(str[index_2 + 1], temp[1]);

                if (strcmp(temp[0], temp[1]) > 0)
                    swap(str[index_2], str[index_2 + 1]);
            } else if (arg == NUMERICAL) {
                int num_index = 0;

                for ( ; str[index_2][num_index] == str[index_2 + 1][num_index]; num_index++);

                if (isdigit(str[index_2][num_index]) && isdigit(str[index_2 + 1][num_index])) {
                    if (getnumber(str[index_2], num_index - 1) > getnumber(str[index_2 + 1], num_index - 1))
                        swap(str[index_2], str[index_2 + 1]);
                } else if (strcmp(str[index_2], str[index_2 + 1]) > 0)
                    swap(str[index_2], str[index_2 + 1]);
            }
        }
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

int main(int argc, char *argv[]) {
    char str[MAX_NUMBER_OF_STRINGS][MAX_STRING_LENGTH];
    int str_index = -1;

    do
        str_index++;
    while (getline(str[str_index]) == GOT_THE_LINE && str_index < MAX_NUMBER_OF_STRINGS);

    if (argc == 1)
        sort(str, str_index, NORMAL);
    else {
        int reverse = 0;

        for (int arg_index = 1; arg_index < argc; arg_index++) {
            if (*argv[arg_index] == '-') {
                switch(*(argv[arg_index] + 1)) {
                    case 'n': 
                        sort(str, str_index, NUMERICAL);
                        break;     
                    case 'r':
                        if (arg_index == 1)
                            sort(str, str_index, NORMAL);

                        reverse = 1;      
                        break;
                    case 'f':
                        sort(str, str_index, FOLD);
                        break;
                    default:
                        printf("INVALID ARGUMENT : %s", argv[arg_index]);
                }
            }
        }
        if (reverse)
            sort(str, str_index, BACKWARDS);
    }

    printf("\n");

    for (int index = 0; index < str_index; index++)
        printf("%s\n", str[index]);

    return 0;
} 
