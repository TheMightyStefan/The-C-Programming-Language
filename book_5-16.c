#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100
#define ALLOC_SIZE 10000
#define MAXLINES 5000
#define MAXLEN 1000

void create_dir(char str[], char temp[]) {
    int temp_index = 0;

    for (int index = 0; str[index] != '\0'; index++)
        if (isspace(str[index]) || isdigit(str[index]) || isalpha(str[index]))
            temp[temp_index++] = str[index];

    temp[temp_index] = '\0';
}

int getnumber(char str[], int index) {
    for ( ; str[index] != '\0' && !isdigit(str[index]); index++);

    int number = 0;

    while (isdigit(str[index]))
        number = 10 * number + (str[index++] - '0');

    return number;
}

int getline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    
    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';

    return i;
}

char *alloc(int n) {
    static char allocbuf[ALLOC_SIZE];
    static char *allocp = allocbuf;

    if (allocbuf + ALLOC_SIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else
        return 0;
}

int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

void writelines(char *lineptr[], int nlines) {
    printf("\n");

    for (int index = 0; index < nlines; index++)
        printf("%s\n", lineptr[index]);
}

int numcmp(char *str_1, char *str_2) { 
    if (atof(str_1) < atof(str_2))
        return -1;
    else if (atof(str_1) > atof(str_2))
        return 1;
    else
        return 0;
}

void swap(void *v[], int i, int j) {
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
void create_lower(char *str, char *lower) {
    int index; 

    for (index = 0; index < strlen(str); index++) {
        if (isupper(str[index]))
            lower[index] = str[index] + 32;
        else
            lower[index] = str[index];
    }
    
    lower[++index] = '\0';
}
     
int foldcmp(char *str_1, char *str_2) {
    char fold_1[MAX_STRING_LENGTH];
    char fold_2[MAX_STRING_LENGTH];

    create_lower(str_1, fold_1);
    create_lower(str_2, fold_2);

    if (strcmp(fold_1, fold_2) < 0)
        return -1;
    else if (strcmp(fold_1, fold_2) > 0)
        return 1;
    else
        return 0;
}

int dircmp(char *str_1, char *str_2) {
    char dir_1[MAX_STRING_LENGTH];
    char dir_2[MAX_STRING_LENGTH];

    create_dir(str_1, dir_1);
    create_dir(str_2, dir_2); 

    if (strcmp(dir_1, dir_2) < 0)
        return -1;
    else if (strcmp(dir_1, dir_2) > 0)
        return 1;
    else
        return 0;
} 

void qqsort(void *v[], int left, int right, int (*comp)(void *, void *)) {
    int last;

    if (left >= right)
        return;

    swap(v, left, (left + right) / 2);
    
    last = left;

    for (int index = left + 1; index <= right; index++)
        if ((*comp)(v[index], v[left]) < 0)
            swap(v, ++last, index);
    
    swap(v, left, last);
    qqsort(v, left, last - 1, comp);
    qqsort(v, last + 1, right, comp);
}

int main(int argc, char *argv[]) {
    char *lineptr[MAXLINES];
    int nlines = readlines(lineptr, MAXLINES);

    if (argc == 1)
        qqsort((void **) lineptr, 0, nlines - 1, (int (*)(void *, void *))(strcmp)); 
    else {
        int reverse = 0;

        for (int arg_index = 1; arg_index < argc; arg_index++) {
            if (*argv[arg_index] == '-') {
                switch(*(argv[arg_index] + 1)) {
                    case 'n':
                        qqsort((void **) lineptr, 0, nlines - 1, (int (*)(void *, void *))(numcmp));
                        break;
                    case 'f':
                        qqsort((void **) lineptr, 0, nlines - 1, (int (*)(void *, void *))(foldcmp));
                        break; 
                    case 'd':
                        qqsort((void **) lineptr, 0, nlines - 1, (int (*)(void *, void *))(dircmp));
                        break;
                    case 'r':
                        reverse = 1;
                        break;
                    default:
                        printf("INVALID ARGUMENT : %s", argv[arg_index]);
                }
            }
        }

        if (reverse)
            for (int reverse_index = 0; reverse_index < nlines / 2; reverse_index++)
                swap((void **) lineptr, reverse_index, nlines - reverse_index - 1);
    }

    writelines(lineptr, nlines);

    return 0;
}
