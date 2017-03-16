#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>

#define MAX_STRING_SIZE 100

void mini_scanf(char *format_string, ...) {
	va_list arg_ptr;
	char *ptr;
	int *int_val;
	char *char_val;
	char *string_val;

	va_start(arg_ptr, format_string);

	for (ptr = format_string; *ptr; ptr++) {
		if (*ptr != '%')
			continue;

		switch (*(++ptr)) {
			case 'd':
				int_val = va_arg(arg_ptr, int *);
				scanf("%d", int_val);
				break;
			case 'c':
				char_val = va_arg(arg_ptr, char *);
				scanf("%c", char_val);
				break;
			case 's':
				for (string_val = va_arg(arg_ptr, char *); *string_val; string_val++)
				scanf("%c", string_val);
				break;
			default:
				break;
		}
	}
}

int main() {
	char str[MAX_STRING_SIZE];

	scanf("%s", &str[0]);

	printf("%s", str);
}
