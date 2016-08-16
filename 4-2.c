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
	
	int index;

	for (index = 0; isspace(string[index]); index++);

	int sign = (string[index] == '-') ? -1 : 1;

	if (string[index] == '+' || string[index] == '-')
		index++;

	double value = 0;

	while (isdigit(string[index])) {
		value = 10.0 * value + (string[index] - '0');
                index++;
        }

	if (string[index] == '.')
		index++;

        int e_index;
        int e_found = 0;

	for (int after_dot_index = index; after_dot_index < strlen(string); after_dot_index++) {
		if (string[after_dot_index] == 'e' || string[after_dot_index] == 'E') {
			e_found = 1;
			e_index = after_dot_index;
		}	
	}

    	double e_power = 0;

	if (e_found) {
		for (int after_e_index = e_index + 2; after_e_index < strlen(string); after_e_index++)
			e_power = e_power * 10 + (string[after_e_index] - '0');
	
		e_power *= (string[e_index + 1] == '-') ? -1 : 1;
	}

        double power;
	
	for (power = 1.0; isdigit(string[index]); index++) {
                value = 10.0 * value + (string[index] - '0');
                power *= 10.0;
        }
	
        return sign * value / power * power_up(10, e_power);
}

int main() {

	char string[100];

	printf("\nYour string : ");
	scanf("%s", string);
	printf("\nYour double : %g\n", string_to_double(string));

	return 0;
}


		
