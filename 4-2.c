#include <ctype.h>
#include <stdio.h>
#include <string.h>

double power_up(int base, int power) {

	double result = 1;
	
	if (power == 0) 
		return 1;
	else if (power < 0) 
		while (power < 0) {
			result /= base;
			power++;
		}		
	else 
		while (power > 0) { 
			result *= base;
			power--;
		}	

	return result;
}

double string_to_double(char string[]) {
	
	double power, value;
	int index, sign = 0;
	double e_power = 0;
	int e_index = 0;
	int e_found = 0;
	int e_sign = 0;

	for (index = 0; isspace(string[index]); index++);

	sign = (string[index] == '-') ? -1 : 1;

	if (string[index] == '+' || string[index] == '-')
		index++;

	for (value = 0.0; isdigit(string[index]); index++)
		value = 10.0 * value + (string[index] - '0');

	if (string[index] == '.')
		index++;

	for (int new_index = index; new_index < strlen(string); new_index++) {
		if (string[new_index] == 'e' || string[new_index] == 'E') {
			e_found = 1;
			e_index = new_index;
		}	
	}
	
	if (e_found) {
		for (int new_index = e_index + 2; new_index < strlen(string); new_index++)
			e_power = e_power * 10 + (string[new_index] - '0'); 
	
		e_sign = (string[e_index + 1] == '-') ? 0 : 1;
	}
	
	for (power = 1.0; isdigit(string[index]); index++) {
		value = 10.0 * value + (string[index] - '0');
		power *= 10.0;
	}

	if (e_sign) 
		return sign * value / power * power_up(10,  e_power);
	else 
		return sign * value / power * power_up(10, -e_power);
}

int main() {

	char string[100];

	printf("\nYour string : ");
	scanf("%s", string);
	printf("\nYour double : %g\n", string_to_double(string));

	return 0;
}


		
