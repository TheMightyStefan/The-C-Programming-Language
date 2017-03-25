#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (strcmp(argv[0], "./lower") == 0) {
		int character = getchar();
       
		 while (character != EOF) {
            putchar(tolower(character));

            character = getchar();
        }
    } else if (strcmp(argv[0], "./upper") == 0) {
		 int character = getchar();

		 while (character != EOF) {
            putchar(toupper(character));

            character = getchar();
        } 
    } else 
		fprintf(stderr, "ERROR : The file is not named lower or upper\n");
    
    return 0;
} 
