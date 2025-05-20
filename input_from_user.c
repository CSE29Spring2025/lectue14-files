#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

int main() {
    char input[MAX_SIZE];
    while (1) {
        printf("Enter an integer (q to quit): ");
        fgets(input, MAX_SIZE, stdin);
        if (input[0] == 'q') {
            break;
        }
        int number = atoi(input);
        if (number % 2 == 0) {
            printf("The number %d is even.\n", number);
        } else {
            printf("The number %d is odd.\n", number);
        }
    }
    return 0;
}
