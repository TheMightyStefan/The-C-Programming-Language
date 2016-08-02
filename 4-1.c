#include <stdio.h>
#include <string.h>

int strrindex(char string[], char target[]) {

    for (int index = strlen(string) - 1; index >= strlen(target); index--) { 
        int string_index = index;
        int target_index = strlen(target) - 1;
        int search_length = 0;

        while (string[string_index] == target[target_index]) {
            string_index--;
            target_index--;
            search_length++;
        }

        if (search_length == strlen(target))
            return string_index + 2;
    }
    
    return -1;
}

int main() {

    char string[] = "agandftargetsdjfsndjfajftargeti";
    char target[] = "target";

    if (strrindex(string, target) >= 0)
         printf("\n%d\n", strrindex(string, target));
    else
        printf("\nNot found\n");

    return 0;
}
