#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
	// char
	printf("CHAR : -%f     -----     %f\n", pow (2.0, (sizeof(char) * 8) - 1), pow (2.0, (sizeof(char) * 8) - 1) - 1);
	printf("SHORT : -%f     -----     %f\n", pow (2.0, (sizeof(short) * 8) - 1), pow (2.0, (sizeof(short) * 8) - 1) - 1);
	printf("INT : -%f     -----     %f\n", pow (2.0, (sizeof(int) * 8) - 1), pow (2.0, (sizeof(int) * 8) - 1) - 1);
        printf("SIGNED LONG : %d     -----     %f\n", 0, pow (2.0, (sizeof(signed long) * 8)));
        printf("SIGNED LONG LONG : %d     -----     %f\n", 0, pow (2.0, (sizeof(signed long long) * 8)));
	printf("UNSIGNED LONG : -%f   -----     %f\n", pow (2.0, (sizeof(unsigned long) * 8) - 1), pow (2.0, (sizeof(unsigned long) * 8) - 1) - 1);
	printf("UNSIGNED LONG LONG : -%f     -----     %f\n", pow (2.0, (sizeof(unsigned long long) * 8) - 1), pow (2.0, (sizeof(unsigned long long) * 8) - 1) - 1);
	return 0;
}  
