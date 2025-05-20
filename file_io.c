#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main() {
    FILE *input_file, *output_file;
    char line[MAX_LINE_LENGTH];
    char *word;

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file");
        return 1;
    }

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file");
        fclose(input_file);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {

        // Tokenize the line by commas
        word = strtok(line, ",");
        while (word != NULL) {
            // Trim leading spaces
            while (*word == ' ') {
                word++;
            }
            fprintf(output_file, "%s\n", word);
            word = strtok(NULL, ",");
        }
    }

    fclose(input_file);
    fclose(output_file);

    printf("Words written to output.txt successfully.\n");
    return 0;
}
