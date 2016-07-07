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
        hexString[1] = hexString[2];
        for (int i = 0; i < length - 1; i++) {
            hexString[i] = hexString[i + 1];
        }
        length -= 2;
    }
    for (int i = 0; i < length; i++) {
        if (isdigit(hexString[i])) {
            integer += (hexString[i] - '0') * pow16(length - i - 1);
        } else 
            switch (hexString[i]) {
                case 'A' :
                    integer += 10 * pow16(length - i - 1);
                    break;
                case 'B' :
                    integer += 11 * pow16(length - i - 1);
                    break;
                case 'C' :
                    integer += 12 * pow16(length - i - 1);
                    break;
                case 'D' :
                    integer += 13 * pow16(length - i - 1);
                    break;
                case 'E' :
                    integer += 14 * pow16(length - i - 1);
                    break;
                case 'F' :
                    integer += 15 * pow16(length - i - 1);
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

