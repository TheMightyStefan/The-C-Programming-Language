#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void expand(char shorthand_notation[], char complete_notation[]) {

    int complete_index = 0;
    for (int index = 0; index < strlen(shorthand_notation); index++) {
        if (isalpha(shorthand_notation[index]) && shorthand_notation[index + 1] == '-' && isalpha(shorthand_notation[index + 2])) {
            while((int)shorthand_notation[index] < (int)shorthand_notation[index + 2]) {
                complete_notation[complete_index] = shorthand_notation[index];
                (int)shorthand_notation[index]++;
                complete_index++;
            }
        } else if (isdigit(shorthand_notation[index]) && isdigit(shorthand_notation[index + 2]) && shorthand_notation[index + 1] == '-') {
            while((int)shorthand_notation[index] < (int)shorthand_notation[index + 2]) {
                complete_notation[complete_index] = shorthand_notation[index];
                (int)shorthand_notation[index]++;
                complete_index++;
            }
        } else if (shorthand_notation[index] != '-') {
            complete_notation[complete_index] = shorthand_notation[index];
            complete_index++;
        }
    } 
}

int main () {
    
    char shorthand_notation[100], complete_notation[250];
    printf("\nGive me the shorthand notation : ");
    scanf("%s", shorthand_notation);    

    expand(shorthand_notation, complete_notation);
 
    printf("\nHere is what you need : \n%s", complete_notation);
    return 0;
}
