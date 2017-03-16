#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int main(int argc, char *argv[]) {
	if (argc != 3)
		fprintf(stderr, "I don't have 2 files :(\n");

	FILE *file_ptr1;
	FILE *file_ptr2;

	file_ptr1 = fopen(argv[1], "r");
	
	if (!file_ptr1) 
		fprintf(stderr, "Error opening file %s\n", argv[1]);

	file_ptr2 = fopen(argv[2], "r");

	if (!file_ptr2)
		fprintf(stderr, "Error opening file %s\n", argv[2]);

	char line_file_1[MAXLINE];
	char line_file_2[MAXLINE];

	int line_number = 1;

	int log_1 = 1;
	int log_2 = 1;

	do {
		log_1 = fgets(line_file_1, MAXLINE, file_ptr1) != NULL;
		log_2 = fgets(line_file_2, MAXLINE, file_ptr2) != NULL;

		if (log_1 && log_2) {
			if (strcmp(line_file_1, line_file_2)) {
				log_1 = 0;
				printf("%d -> %s\n%d -> %s\n", line_number, line_file_1, line_number, line_file_2);
			}	
		
			line_number++;
		}

	} while (log_1 && log_2);

	return 0;
}
