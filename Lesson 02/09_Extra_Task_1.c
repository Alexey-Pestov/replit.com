// Given an array of 7 numbers. Implement a function find():
// • that takes an array (of length 7) and a number
// • It should return the first index of that number in the array or -1 if it isn’t present

#include <stdio.h>

// Function to find the first index of a number in an array
int find(int numbers[7], int target) {
    for (int i = 0; i < 7; i++) {
        if (numbers[i] == target) {
            return i;  // Return the first index where the target is found
        }
    }
    return -1;  // Return -1 if the target isn't found in the array
}

int main(void) {
    int numbers[7];

    // Read 7 numbers from the console and store them in an array
    printf("Enter 7 numbers: ");
    for (int i = 0; i < 7; i++) {
        scanf("%d", &numbers[i]);
    }

    int target;
    // Read the target number from the console
    printf("Enter the number to find: ");
    scanf("%d", &target);

    // Find the first index of the target number in the array
    int index = find(numbers, target);

    // Print the result
    if (index != -1) {
        printf("The number %d is found at index %d\n", target, index);
    } else {
        printf("The number %d is not found in the array\n", target);
    }

    return 0;
}

// gcc 09_Extra_Task_1.c -o P
// ./P