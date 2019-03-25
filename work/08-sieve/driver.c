#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "sieve.h"

int main() {
  printf("prime n = %d: %d\n", 200, sieve(200));
  printf("prime n = %d: %d\n", 1000, sieve(1000));
  printf("prime n = %d: %d\n", 1000000, sieve(1000000));
}