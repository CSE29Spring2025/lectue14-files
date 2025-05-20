#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main() {
    int input_fd, output_fd;
    ssize_t bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];

    // Open input file (read-only)
    input_fd = open("input.txt", O_RDONLY);
    if (input_fd < 0) {
        printf("Error opening input file");
        exit(1);
    }

    // Open/create output file (write-only, truncate if exists, create if not)
    output_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC);
    if (output_fd < 0) {
        printf("Error opening/creating output file");
        close(input_fd);
        exit(1);
    }

    // Read from input and write to output
    while ((bytes_read = read(input_fd, buffer, BUFFER_SIZE)) > 0) {
        printf("Read %zd bytes from input file\n", bytes_read);
        bytes_written = write(output_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            printf("Error writing to output file");
            close(input_fd);
            close(output_fd);
            exit(1);
        }
    }

    // Close files
    close(input_fd);
    close(output_fd);

    printf("File copied successfully using Unix I/O.\n");
    return 0;
}
