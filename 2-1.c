#include <stdio.h>
#include <stdlib.h>

unsigned long long pow2(int exponent) {
	 unsigned long long pow = 1;
	 while (exponent > 0) {
		pow *= 2;
		exponent--;
	 }
	 return pow;
}

int main()
{	unsigned long long max_range = 0, min_range = 0;	
	//char 
	min_range = -pow2((sizeof(char) * 8) - 1);
	max_range =  pow2((sizeof(char) * 8) - 1) - 1;

	printf("\nCHAR : %lld    ----    %lld\n", min_range, max_range);

	//unsigned char
	min_range = 0;
	max_range = (pow2(sizeof(unsigned char) * 4) - 1) * (pow2(sizeof(unsigned char) * 4) + 1);

	printf("\nUNSIGNED CHAR : %lld    ----    %lld\n", min_range, max_range);

	//short
	min_range = -pow2((sizeof(short) * 8) - 1);
	max_range =  pow2((sizeof(short) * 8) - 1) - 1;

	printf("SHORT : %lld    ----    %lld\n", min_range, max_range);

	//unsigned short
	min_range = 0;
	max_range = (pow2(sizeof(unsigned short) * 4) - 1) * (pow2(sizeof(unsigned short) * 4) + 1);

	printf("UNSIGNED SHORT : %lld    ----    %lld\n", min_range, max_range);

	//int
	min_range = -pow2((sizeof(int) * 8) - 1);
	max_range =  pow2((sizeof(int) * 8) - 1) - 1;

	printf("INT : %lld    ----    %lld\n", min_range, max_range);

	//unsigned int
	min_range = 0;
	max_range = (pow2(sizeof(unsigned int) * 4) - 1) * (pow2(sizeof(unsigned int) * 4) + 1

	printf("UNSIGNED INT : %lld    ----    %lld\n", min_range, max_range);

	//long
	min_range = -pow2((sizeof(long) * 8) - 1);
	max_range =  pow2((sizeof(long) * 8) - 1) - 1;

	printf("LONG : %lld    ----    %lld\n", min_range, max_range);

	//long long
	min_range = -pow2((sizeof(long long) * 8) - 1);
	max_range =  pow2((sizeof(long long) * 8) - 1) - 1;

	printf("LONG LONG : %lld    ----    %lld\n", min_range, max_range);

	//unsigned long
	min_range = 0;
	max_range = (pow2(sizeof(unsigned long) * 4) - 1) * (pow2(sizeof(unsigned long) * 4) + 1);

	printf("UNSIGNED LONG : %llu    ----    %llu\n", min_range, max_range);
	
	//unsigned long long 
	min_range = 0;
	max_range = (pow2(sizeof(unsigned long long) * 4) - 1) * (pow2(sizeof(unsigned long long) * 4) + 1);

	printf("UNSIGNED LONG LONG : %llu    ----    %llu\n", min_range, max_range);

	return 0;
}  
