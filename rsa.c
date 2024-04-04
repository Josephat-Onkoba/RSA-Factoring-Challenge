#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to factorize a number n
void factorize(int n) {
    int p, q;

    // Iterate from 2 to n/2 to find factors
    for (p = 2; p <= n / 2; ++p) {
        // If p is a factor of n and both p and n/p are prime, print the factorization
        if (n % p == 0 && is_prime(p) && is_prime(n / p)) {
            printf("%d=%d*%d\n", n, p, n / p);
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
