#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int main() {
    FILE *input_file = fopen("in.txt", "r");
    FILE *output_file = fopen("out.txt", "w");
    if (input_file == NULL || output_file == NULL) {
        printf("Error opening files.\n");
        return 1;
    }
    int number;
    char line[MAX_SIZE];
    while (fgets(line, MAX_SIZE, input_file)) {
        number = atoi(line);
        fprintf(output_file, "%d\n", number * number);
    }
    fclose(input_file);
    fclose(output_file);
    return 0;
}
