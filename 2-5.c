#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int any(char str1[], char str2[]) 
{   
    int stop = 0, first_location = 0;
    for (int index_str1 = 0; index_str1 < strlen(str1) && (!stop); index_str1++) {
        for (int index_str2 = 0; index_str2 < strlen(str2); index_str2++) {
            if (str1[index_str1] == str2[index_str2]) {
                stop = 1;
                first_location = index_str1 + 1;
            }
        }
    }
    if (stop) {
        return first_location;
    } else {
        return -1;
    }
}

int main() 
{
    char str1[50], str2[50];
    printf("\n\nGive me the first string : ");
    scanf("%s", str1);
    printf("\nGive me the second string : ");
    scanf("%s", str2);
    printf("Here is the first location in the first string where any character from the string 2 occurs : %d\n\n", any(str1, str2));
    return 0;
}

