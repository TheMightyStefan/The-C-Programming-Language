#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void squeeze(char str1[], char str2[])
{
    int index_new_str = 0, index_str2 = 0, delete_this_char = 0;
    for (int index_str1 = 0; index_str1 < strlen(str1); index_str1++) {
        delete_this_char = 0;
        for (index_str2 = 0; index_str2 < strlen(str2); index_str2++) {
            if (str1[index_str1] == str2[index_str2]) {
                delete_this_char = 1;
            }
        }
        if (!delete_this_char) {
            str1[index_new_str++] = str1[index_str1];
        }
    }
    str1[index_new_str] = '\0';
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
