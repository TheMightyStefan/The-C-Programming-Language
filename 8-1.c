#include <stdio.h>
#include <fcntl.h>

#define BUFFER_SIZE 2048

void file_copy(int to_copy, int result) {
	char buffer[BUFFER_SIZE];
	int n = read(to_copy, buffer, BUFFER_SIZE);

	while (n > 0) {
		write(result, buffer, n);
		n  = read(to_copy, buffer, BUFFER_SIZE);
	}
}

int main(int argc, char *argv[]) {
	if (argc == 1)
		file_copy(0, 1);
	else {
		argv++;

		while (--argc > 0) {
	 		int file_descriptor = open(*argv, O_RDONLY, 0);
	
			if (file_descriptor == -1) {
				printf("Cat : Can't open %s\n", *argv);
				return 1;
			} else {
				file_copy(file_descriptor, 1);
				close(file_descriptor);
			}
		}
	}
	
	return 0;
}
