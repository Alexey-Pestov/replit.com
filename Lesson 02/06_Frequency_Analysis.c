// Given an array of 7 numbers.
// For each number count how many times it is included in the array

#include <stdio.h>

int main(void) {
  int numbers[7];

  for (int i = 0; i < 7; i++) {
    scanf("%d", &numbers[i]);
  }

  int count = 0; // Объявляем переменную count здесь

  for (int i = 0; i < 7; i++) {
    int goal = numbers[i];
    count = 0;
    for (int j = 0; j < 7; j++) { // Используем j для внутреннего цикла
      if (numbers[j] == goal) {
        count++;
      }
    }
    // Возможно, здесь вы хотите вывести count для каждого числа:
    printf("Число %d встречается %d раз(а)\n", goal, count);
  }

  return 0;
}

// gcc program_006.c -o P1
// ./P1