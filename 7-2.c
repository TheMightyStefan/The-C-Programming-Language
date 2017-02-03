#include <stdio.h>
#include <ctype.h>

#define MAXLINE 70
#define HEXADECIMAL 16

int increment(int position, int add) {
    if (position + add < MAXLINE)
        return position + add;
    else {
        printf("\n");
        return add;
    }
}  

int main() {
    int character = getchar();
    int position = 0;

    if (character != EOF) {
        do {
            if (iscntrl(character) || character == ' ') {
                position = increment(position, HEXADECIMAL);

                printf("\\%03x", character);

                if (character == '\n')
                    position = 0;

                printf("\n");
            } else {
                position = increment(position, 1);
                printf("%c", character);
            }

            character = getchar();
        } while (character != EOF);
    }

    return 0;
}
