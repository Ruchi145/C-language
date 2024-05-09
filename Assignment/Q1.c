#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}


void print_prime_series(int n) {
    int count = 0;
    int num = 2;
    while (count < n) {
        if (is_prime(num)) {
            printf("%d ", num);
            count++;
        }
        num++;
    }
    printf("\n");
}

int sum_of_prime_numbers(int n) {
    int sum = 0;
    int count = 0;
    int num = 2;
    while (count < n) {
        if (is_prime(num)) {
            sum += num;
            count++;
        }
        num++;
    }
    return sum;
}

int main(int argc, char *argv[]) {
    if (argc != 3 || strcmp(argv[1], "-n") != 0) {
        printf("Usage: %s -n <number>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[2]);

    printf("Series of first %d prime numbers: ", n);
    print_prime_series(n);

    int sum = sum_of_prime_numbers(n);
    printf("Sum of first %d prime numbers: %d\n", n, sum);

    return 0;
}
