#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void escape(char modified_string[], char original_string[]) {

    int new_index = 0;
    for (int index = 0; index <= strlen(original_string); index++) {
         switch(original_string[index]) {
            case '\n' : 
                modified_string[new_index] = '\\';
                modified_string[new_index + 1] = 'n';
                new_index += 2;
                break;
            case '\t' :
                modified_string[new_index] = '\\';
                modified_string[new_index + 1] = 't';
                new_index += 2;
                break;
            default :
                modified_string[new_index] = original_string[index];
                new_index++;
                break;
        }   
    }
    modified_string[new_index] = '\0';
}

int main () {

    char modified_string[100],
         original_string[100] = "abcdef\tadafa\nhahaha\n";

    escape(modified_string, original_string);

    printf("\nHere is my version : \n\n%s\n\n", modified_string);
    return 0;
}

