// 1. Implement function double compute_average(int numbers[5]) that returns average value of 5 numbers;
// 2. Read 5 numbers from the console and store them in an array;
// 3. Print the answer computed by the function.

#include <stdio.h>

// Function to compute the average of 5 numbers
double compute_average(int numbers[5]) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += numbers[i];
    }
    return sum / 5.0; // Return the average as a double
}

int main(void) {
    int numbers[5];

    // Read 5 numbers from the console and store them in an array
    printf("Enter 5 numbers: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &numbers[i]);
    }

    // Compute the average using the function and print the result
    double average = compute_average(numbers);
    printf("The average is: %.2f\n", average);

    return 0;
}

// gcc Average Value.c -o P1
// ./P1