#include <stdio.h>
#include <stdlib.h>

long long pow2(int exponent) 
{
	 int pow = 1;
	 while (exponent > 0) {
		pow *= 2;
		exponent --;
	 }
	 return pow;
}

int main()
{
	
	printf("CHAR : -%lld     -----     %lld\n", pow2((sizeof(char) * 8) - 1), pow2((sizeof(char) * 8) - 1) - 1);
	printf("SHORT : -%lld     -----     %lld\n", pow2((sizeof(short) * 8) - 1), pow2((sizeof(short) * 8) - 1) - 1);
	printf("INT : -%lld -----     %lld\n", pow2((sizeof(int) * 8) - 1), pow2((sizeof(int) * 8) - 1) - 1);
        printf("SIGNED LONG : 0     -----     %lld\n", pow2((sizeof(signed long) * 8)));
        printf("SIGNED LONG LONG : 0     -----     %lld\n", pow2((sizeof(signed long long) * 8)));
	printf("UNSIGNED LONG : -%lld   -----     %lld\n", pow2((sizeof(unsigned long) * 8) - 1), pow2((sizeof(unsigned long) * 8) - 1) - 1);
	printf("UNSIGNED LONG LONG : -%lld     -----     %lld\n", pow2((sizeof(unsigned long long) * 8) - 1), pow2((sizeof(unsigned long long) * 8) - 1) - 1);
	return 0;
}  
