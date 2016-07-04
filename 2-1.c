#include <stdio.h>
#include <stdlib.h>

long long pow2(int exponent) {
	 int pow = 1;
	 while (exponent > 0) {
		pow *= 2;
		exponent--;
	 }
	 return pow;
}

int main()
{
	long long max_range = 0, min_range = 0;	

	// char 
	min_range = -pow2((sizeof(char) * 8) - 1);
	max_range =  pow2((sizeof(char) * 8) - 1) - 1;

	printf("\nCHAR : %lld    ----    %lld\n", min_range, max_range);

	min_range = 0;
	max_range = 0;

	//short
	min_range = -pow2((sizeof(short) * 8) - 1);
	max_range =  pow2((sizeof(short) * 8) - 1) - 1;

	printf("SHORT : %lld    ----    %lld\n", min_range, max_range);

	min_range = 0;
	max_range = 0;

	//int
	min_range = -pow2((sizeof(int) * 8) - 1);
	max_range =  pow2((sizeof(int) * 8) - 1) - 1;

	printf("INT : %lld    ----    %lld\n", min_range, max_range);

	min_range = 0;
	max_range = 0;

	//long
	min_range = -pow2((sizeof(long) * 8) - 1);
	max_range =  pow2((sizeof(long) * 8) - 1) - 1;

	printf("LONG : %lld    ----    %lld\n", min_range, max_range);

	min_range = 0;
	max_range = 0;

	//long long
	min_range = -pow2((sizeof(long long) * 8) - 1);
	max_range =  pow2((sizeof(long long) * 8) - 1) - 1;

	printf("LONG LONG : %lld    ----    %lld\n", min_range, max_range);

	min_range = 0;
	max_range = 0;

	//unsigned long
	min_range = 0;
	max_range = pow2(sizeof(unsigned long) * 8);

	printf("UNSIGNED LONG : %lld    ----    %lld\n", min_range, max_range);
	
	min_range = 0;
	max_range = 0;

	//unsigned long long 
	min_range = 0;
	max_range = pow2(sizeof(unsigned long long) * 8);

	printf("UNSIGNED LONG LONG : %lld    ----    %lld\n", min_range, max_range);

	min_range = 0;
	max_range = 0;

	return 0;
}  
