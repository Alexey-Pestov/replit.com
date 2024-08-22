// Implement the Luhn algorithm.
// Program should take a 10-digit number and print if it is valid, assuming that the last digit is the check digit.
// https://ru.wikipedia.org/wiki/%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC_%D0%9B%D1%83%D0%BD%D0%B0

#include <stdio.h>

// Function to implement the Luhn algorithm
int luhn_algorithm(int digits[10]) {
    int sum = 0;

    // Process the first 9 digits
    for (int i = 0; i < 9; i++) {
        int value = digits[i];

        // Double every second digit from the right (i.e., starting with the 8th digit)
        if (i % 2 == 0) {
            value *= 2;
            // If doubling results in a number greater than 9, sum the digits of the result
            if (value > 9) {
                value -= 9; // equivalent to summing the digits
            }
        }

        sum += value;
    }

    // Calculate the check digit
    int calculated_check_digit = (sum * 9) % 10;

    // Compare the calculated check digit with the actual check digit
    return calculated_check_digit == digits[9];
}

int main(void) {
    int digits[10];

    // Read the 10-digit number
    printf("Enter a 10-digit number: ");
    for (int i = 0; i < 10; i++) {
        scanf("%1d", &digits[i]); // Read each digit separately
    }

    // Validate the number using the Luhn algorithm
    if (luhn_algorithm(digits)) {
        printf("The number is valid.\n");
    } else {
        printf("The number is invalid.\n");
    }

    return 0;
}

// gcc 10_Luhn_algorithm.c -o P
// ./P