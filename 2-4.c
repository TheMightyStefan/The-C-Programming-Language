#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search(char str[], char target) {

    for (int index = 0; index < strlen(str); index++) {
        if (str[index] == target) 
            return 1;
        }
    return 0;   
}

//Delete all occurences of target in str         

void delete(char str[], char target) {
    
    int new_index = 0;
    for (int index = 0; index < strlen(str); index++) {
        if (!(str[index] == target)) {
            str[new_index++] = str[index];
        }
    }
    str[new_index] = '\0';
}       

void squeeze(char str1[], char str2[]) {

    for (int index_str2 = 0; index_str2 < strlen(str2); index_str2++) {
        if (search(str1, str2[index_str2])) {
            delete(str1, str2[index_str2]);
        }
    }
}
int main()
{
    char str1[50], str2[50];
    printf("\n\nGive me a string : ");
    scanf("%s", str1);
    printf("\nCharacters to delete : ");
    scanf("%s", str2);

    squeeze(str1, str2);

    printf("\nHere is your new string : %s", str1);
    printf("\n\n");
    return 0;
}  
