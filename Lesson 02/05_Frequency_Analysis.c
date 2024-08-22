// Given an array of 7 numbers.
// For the first number count how many times it is included in the array.

#include <stdio.h>

int main(void) {
  int numbers[7];
  for (int i = 0; i<7; i++){
    scanf("%d", &numbers[i]);
  }
  int goal = numbers[0];
  int count = 0;
  for (int i = 0; i<7;i++){
    if (numbers[i] == goal){
      count++;
    }
  }
  printf("%d", count);
}

// gcc program_005.c -o P1
// ./P1