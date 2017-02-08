#include <stdarg.h>
#include <stdio.h>

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

        switch (format_string[++index]) {
            case 'd':
                int_val = va_arg(argument_ptr, int);
                
                printf("%d", int_val);
                break;
            case 'f':
                double_val = va_arg(argument_ptr, double);
            
                printf("%f", double_val);
                break;
            case 's':
                for (string_val = va_arg(argument_ptr, char *); *string_val; string_val++)
                    putchar(*string_val);

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

    mini_printf("%d, %f", cos, v);

    return 0;
}
