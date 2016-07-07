#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void squeeze(char str1[], char str2[])
{
    int i, j = 0, delete = 0;
    for (i = 0; i < strlen(str1); i++) {
        delete = 0;
        for (int k = 0; k < strlen(str2); k++) {
            if (str1[i] == str2[k]) {
                delete = 1;
            }
        }
        if (!delete) {
            str1[j++] = str1[i];
        }
    }
    str1[j] = '\0';
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
