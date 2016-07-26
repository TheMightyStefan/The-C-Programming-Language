#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void expand(char shorthand[], char complete[]) {

    int complete_index = 0;
    for (int index = 0; index < strlen(shorthand) - 2; index++) {
        if (isalpha(shorthand[index]) && shorthand[index + 1] == '-' && isalpha(shorthand[index + 2])) {
            int FIRST_ASCII = (int)shorthand[index],
                LAST_ASCII = (int)shorthand[index + 2];
            while(FIRST_ASCII <= LAST_ASCII) {
                complete[complete_index] = (char)FIRST_ASCII;
                complete_index++;
                FIRST_ASCII++;
            }
        } else if (isdigit(shorthand[index]) && isdigit(shorthand[index + 2]) && shorthand[index + 1] == '-') {
            int FIRST_ASCII = (int)shorthand[index],
                LAST_ASCII = (int)shorthand[index + 2];
            while(FIRST_ASCII <= LAST_ASCII) {
                complete[complete_index] = (char)FIRST_ASCII;
                complete_index++;
                FIRST_ASCII++;
            }
        } else if (shorthand[index] != '-') {
            complete[complete_index] = shorthand[index];
            complete_index++;
        }
    }
    complete[complete_index] = '\0'; 
}

int main () {
    
    char shorthand[100], complete[250];
    printf("\nGive me the shorthand notation : ");
    scanf("%s", shorthand);    

    expand(shorthand, complete);
 
    printf("\nHere is what you need : \n%s", complete);
    return 0;
}
