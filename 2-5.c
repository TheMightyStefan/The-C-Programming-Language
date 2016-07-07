#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int any(char s1[], char s2[]) 
{   
    int stop = 0, first_location = 0;
    for (int i = 0; i < strlen(s1) && (!stop); i++) {
        for (int j = 0; j < strlen(s2); j++) {
            if (s1[i] == s2[j]) {
                stop = 1;
                first_location = i + 1;
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
    char s1[50], s2[50];
    printf("\n\nGive me the first string : ");
    scanf("%s", s1);
    printf("\nGive me the second string : ");
    scanf("%s", s2);
    printf("Here is the first location in the first string where any character from the string 2 occurs : %d\n\n", any(s1, s2));
    return 0;
}

