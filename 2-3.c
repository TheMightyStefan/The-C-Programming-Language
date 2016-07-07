#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int pow16(int exponent) {
    int pow = 1;
    if (exponent == 0) {
        return 1;
    } else { 
        while (exponent > 0) {
             pow *= 16;
             exponent--;
        }
        return pow;
    }
}

int htoi(char hexString[]) {
    int integer = 0;
    int length = strlen(hexString);
    if (hexString[0] == '0' && (hexString[1] == 'x' || hexString[1] == 'X')) {
            for (int i = 0; i < length - 1; i++) {
            hexString[i] = hexString[i + 2];
        }
        length -= 2;
    }
    for (int i = 0; i < length; i++) {
        if (isdigit(hexString[i])) {
            integer += (hexString[i] - '0') * pow16(length - i - 1);
        } else if (hexString[i] >= 'A' && hexString[i] <= 'F') {
            integer += ((int)hexString[i] - 55) * pow16(length - i - 1);                
        } else {
            printf("\n\nThis number is not hexadecimal !!\n\n");
            break;
        }
    }
    return integer;
}

int main() {
    char hexString[50];
    printf("\n\nGive me the hexadecimal number : ");
    scanf("%s", hexString);
    printf("\nHere is your decimal number : %d ", htoi(hexString));
    return 0;
}

