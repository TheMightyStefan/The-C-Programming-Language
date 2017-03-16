#include <stdio.h>
#include <stdlib.h>

#define LINES_ON_PAGE 20

void print_file(char *file_name) {
	FILE *file_ptr = fopen(file_name, "r");
	int page_number = 1;
	int line_counter = 0;
	int new_page = 1;

	if (file_ptr != NULL) {
		char character = fgetc(file_ptr);

		while (character != EOF) {
			if (new_page) {
				printf("\t\t[%s] -> Page %d Start\n", file_name, page_number);

				new_page = 0;
				line_counter = 1;
			}
	
			putchar(character);

			if (character == '\n' && ++line_counter > LINES_ON_PAGE) {
				printf("\t\t[%s] -> Page %d End\n", file_name, page_number);

				putchar('\n');
				new_page = 1;
				page_number++;
			}
		
			character = fgetc(file_ptr);
		}

		if (!new_page)
			printf("\t\t[%s] -> Page %d End\n", file_name, page_number);

		putchar('\n');
		fclose(file_ptr);
	}
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "I have no files");
		return EXIT_FAILURE;
	}

	for (int arg_index = 1; arg_index < argc; arg_index++) 
		print_file(argv[arg_index]);

	return 0;
}

