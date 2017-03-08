#include <stdarg.h>
#include <ctype.h>
#include <stdio.h>

int get_thing(char *string, int *index) {
	int thing = 0;

	for ( ;	isdigit(string[*index]); (*index)++) 
		thing  = thing * 10 + (string[*index] - '0');

	return thing;
}

int get_digits(int number) {
	int digits = 0;

	while (number) {
		number /= 10;
		digits++;
	}
		
	return digits;
}

int get_digits_float(double number) {
	int int_part = (int)number;
	int digits = 0;

	float e = 0.000001;

	while (!(number - e < number && number < number + e)) {
		number *= 10;
		digits++;
	}
	
	digits += get_digits(int_part);

	return digits;
}	

void mini_printf(char *format_string, ...) {
    va_list argument_ptr;
    char *string_val;
    int int_val;
    double double_val;

    va_start(argument_ptr, format_string);

    for (int index = 0; format_string[index] != '\0'; index++) {
        if (format_string[index] != '%') {
            putchar(format_string[index]);
            continue;
        }

		int width = 0;
		int precision = 0;

		if (isdigit(format_string[++index])) {
			width = get_thing(format_string, &index);

			if (format_string[index] == '.') {
				index++;
				precision = get_thing(format_string, &index);
			}

		}
		
        switch (format_string[index]) {
            case 'd':
                int_val = va_arg(argument_ptr, int);

				printf("%d", int_val);

				if (width > get_digits(int_val)) {
					while (width - get_digits(int_val)) {
						printf("#");
		
						width--;
					}	
				}	
					
                break;
            case 'f':
                double_val = va_arg(argument_ptr, double);

            
                printf("%f", double_val);
                break;
            case 's':
				
                for (string_val = va_arg(argument_ptr, char *); *string_val; string_val++)
                    putchar(*string_val);

				if (width > strlen(string_val)) {
					while (width - strlen(string_val)) {
						printf("#");
	
						width--;
					}
				}

                break;
            default:
                putchar(format_string[index]);
                break;
        }
    }

    va_end(argument_ptr);
}

int main() {
    int cos = 5;
    double v = 4.421;
	char s[] = "ionel";

    mini_printf("%4.5d, %14.23f, %15s\n", cos, v, s);

    return 0;
}
