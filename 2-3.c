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

    const int asciiHexDiff = 'A' - 10;
    int integerFromHex = 0;
    int lengthOfHex = strlen(hexString);

    if (hexString[0] == '0' && (hexString[1] == 'x' || hexString[1] == 'X')) {
        for (int index = 0; index < lengthOfHex - 1; index++) {
            hexString[index] = hexString[index + 2];
            if (index == lengthOfHex - 1) {
                hexString[index] = '\0';    
                }
            }
        lengthOfHex -= 2;
    }
   
    for (int index = 0; index < lengthOfHex; index++) {
              if (isdigit(hexString[index])) {
           integerFromHex += (hexString[index] - '0') * pow16(lengthOfHex - index - 1); 
       } else if (hexString[index] >= 'A' && hexString[index] <= 'F') {
           integerFromHex += ((int)hexString[index] - asciiHexDiff) * pow16(lengthOfHex - index - 1);                
       } else {
           return -1;
       }
    }
    return integerFromHex;
}

int main() {

    char hexString[50];
    printf("\n\nGive me the hexadecimal number : ");
    scanf("%s", hexString);
    int integerFromHex = htoi(hexString);
    if (integerFromHex == -1) {
        printf("\n\nThis is not a hexadecimal number ! \n\n");
    } else {
        printf("\nHere is your decimal number : %d ", integerFromHex);
    }
     return 0;
}

