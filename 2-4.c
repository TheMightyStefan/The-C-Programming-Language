#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search(char str1[], char character_to_search_for) {

    int found = 0;
    for (int index_str1 = 0; (!found) && index_str1 < strlen(str1); index_str1++) {
            if (str1[index_str1] == character_to_search_for) 
                found = 1;
        }
    if (found) 
        return 1;
    else 
        return 0;   
}
         
void delete(char str[], char char_to_delete) {
    
    int index_after_delete = 0;
    for (int index_str = 0; index_str < strlen(str); index_str++) {
        if (!(str[index_str] == char_to_delete)) {
            str[index_after_delete++] = str[index_str];
        }
    }
    str[index_after_delete] = '\0';
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
