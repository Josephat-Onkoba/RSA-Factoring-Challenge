#include <stdio.h>
#include <stdlib.h>

// Function to factorize a number n
void factorize(int n) {
    int i, j;

    // Iterate from 2 to n/2 to find factors
    for (i = 2; i <= n / 2; ++i) {
        // If i is a factor of n, print the factorization
        if (n % i == 0) {
            printf("%d=%d*%d\n", n, i, n / i);
            return;
        }
    }

    // If no factors found, n is a prime number
    printf("%d=%d*%d\n", n, n, 1);
}

int main(int argc, char *argv[]) {
    FILE *file;
    int num;

    // Check if filename is provided as argument
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    // Open the file for reading
    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read numbers from file and factorize them
    while (fscanf(file, "%d", &num) == 1) {
        factorize(num);
    }

    // Close the file
    fclose(file);

    return 0;
}
