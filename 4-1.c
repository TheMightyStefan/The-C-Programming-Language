#include <stdio.h>
#include <string.h>

int strrindex(char string[], char target[]) {

    for (int index = strlen(string) - 1; index >= strlen(target); index--) { 
        signed int string_index = index;
        signed int target_index = strlen(target) - 1;
        int search_length = 0;

        while (string[string_index] == target[target_index]) {
            search_length++;
            string_index--;
            target_index--;

        }

        if (search_length == strlen(target))
            return string_index + 2;
    }
    
    return -1;
}

int main() {

    char string[100];
    char target[100];

    scanf("%s", string);
    scanf("%s", target);

    if (strrindex(string, target) != -1)
         printf("\n%d\n", strrindex(string, target));
    else
        printf("\nNot found\n");

    return 0;
}
