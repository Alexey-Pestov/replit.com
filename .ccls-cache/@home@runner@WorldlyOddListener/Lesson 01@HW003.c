// Read integer N. Print integers from 1 to N, but print “Fizz” if an integer is divisible by 3, “Buzz” if an integer is divisible by 5, and “FizzBuzz” if an integer is divisible by both 3 and 5.

#include <stdio.h>

int main() {
    int N;

    // Считываем число N
    printf("Enter the value of N: ");
    scanf("%d", &N);

    // Проходим по числам от 1 до N
    for (int i = 1; i <= N; i++) {
        // Проверяем, делится ли число на 3 и на 5
        if (i % 3 == 0 && i % 5 == 0) {
            printf("FizzBuzz\n");
        }
        // Проверяем, делится ли число только на 3
        else if (i % 3 == 0) {
            printf("Fizz\n");
        }
        // Проверяем, делится ли число только на 5
        else if (i % 5 == 0) {
            printf("Buzz\n");
        }
        // Если число не делится ни на 3, ни на 5
        else {
            printf("%d\n", i);
        }
    }

    return 0;
}

// gcc HW003.c -o HW3
// ./HW3