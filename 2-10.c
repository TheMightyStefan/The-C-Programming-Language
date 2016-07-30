#include <stdio.h>
#include <stdlib.h>

int lower(int c) {

    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}

int main() {

    int c = 'F';
    printf("\n%c --> %c\n", c, lower(c));
    return 0;
}
