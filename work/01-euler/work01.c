// systems work01

// Problem 1: Find the sum of all the multiples of 3 or 5 below 1000.
#include <stdio.h>

int p1() {
  int sum = 0;
  for(int i = 1; i < 1000; i++) {
    if (i % 3 == 0 || i % 5 == 0){
      sum += i;
    }
  }
  printf("%d", sum);
  printf("\n");
}

// Problem 6: Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

int p6() {
  int sum_squares = 0;
  int sum = 0;
  for(int i = 1; i < 100; i++) {
    sum_squares += i * i;
    sum += i;
  }
  int square_sum = sum * sum;
  int diff = square_sum - sum_squares;
  printf("%d", diff);
  printf("\n");
}

int main() {
  p1();
  p6();
}

