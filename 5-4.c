#include <stdio.h>
#include <string.h>

int strend(char search[], char target[]) {
    int search_length = strlen(search) - 1;
    int target_length = strlen(target) - 1;

    if (search_length < target_length || !target_length || !search_length)
        return 0;

    for ( ; target_length > -1; target_length--, search_length--) {
        if (*(target + target_length) != *(search + search_length))
                return 0;
    }
    
    return 1;
}

int main() {
    char search[] = "Ionel il cheama pe Gigel";
    char target[] = "Gigel";

    if (strend(search, target))
        printf("Found\n");
    else
        printf("Not Found\n");

    return 0;
}
