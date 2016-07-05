#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int c, i = 0, stop = 0;
    while (!stop) {
        c = getchar();
        if (i == lim - 1) {
            stop = 1;
        } else if (c == EOF) {
            s[i] = '\0';
            stop = 1;
        } else if (c == '\n') {
            s[i] = c;
            ++i;
            stop = 1;
        } else { 
            s[i] = c;
            i++;
        }
    }
    return 0;
}
