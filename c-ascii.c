#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
	// Initializing values
	int i;	
	
	// Checking if command arguments is not 2
	if (argc != 2) {
		// Tell user how to call the program properly
		write(STDERR_FILENO, "Usage: ./prog filename\n", 24);
		return 1;
	}

	// Creating file
	int create_fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);

	// Checking if the value of create_fd is less than 0
	if (create_fd < 0) {
		perror("open for writing");
		return 1;
	}

	// Setting up the buffer
	char buffer[8];

	// Looping to add the numbers 32 - 126 to the text file
	for (i = 32; i <= 126; ++i) {
		// Writing the ints into the file
		int len = snprintf(buffer, sizeof(buffer), "%d\n", i);
		write(create_fd, buffer, len);
	}
	// Closing create_fd
	close(create_fd);

	// Opening file to read only
	int read_fd = open(argv[1], O_RDONLY);

	// Checking if read_fd is less than zero
	if (read_fd < 0) {
		perror("open for reading");
		return 1;
	}
	
	// Setting up variables
	char ch;
	char num_buf[8];
	int idx = 0;

	// While loop to handle each character
	while(read(read_fd, &ch, 1) == 1) {
		if (ch >= '0' && ch <= '9') {
			num_buf[idx++] = ch;
		} else if (ch == '\n' || ch == ' ') {
			if (idx > 0) {
				num_buf[idx] = '\0';
				int num = atoi(num_buf);

				char num_str[8];
				int len = snprintf(num_str, sizeof(num_str), "%d", num);
				
				// Writing the number string followed by a space
				write(STDOUT_FILENO, num_str, len);
				write(STDOUT_FILENO, " ", 1);
	
				// Writing the ASCII character based on the value
				char c = (char)num;
				write(STDOUT_FILENO, &c, 1);

				// Writing a newline character
				write(STDOUT_FILENO, "\n", 1);
				idx = 0;
			}
		}
	}

	// Closes the file
	close(read_fd);

	// Exits program with no errors
	return 0;
}
