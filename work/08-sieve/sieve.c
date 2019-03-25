#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "sieve.h"

int sieve(int targetPrime) {
  int array_size = targetPrime * log(targetPrime) * 1.15;
  char * primes = (char *) malloc(array_size);

  int factor;
  for (factor = 2; factor < array_size; factor++) {
    int curr;
    for (curr = factor*2; curr < array_size; curr += factor){
      primes[curr] = 'C';
    }
  }
  
  int prime_count = 0;
  int curr = 2;
  int last_prime;
  
  while(prime_count != targetPrime){
    if (primes[curr] != 'C'){
      prime_count += 1;
      last_prime = curr;
    }
    curr++;
  }
  return last_prime;
}