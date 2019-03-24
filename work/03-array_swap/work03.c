#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  // set randomseed
  srand(time(NULL));

  // initialize array
  int arr[10];

  // populate array
  int i;
  for (i = 0; i < 10; i++){
    arr[i] = rand();
  }

  // set last value to 0
  arr[9] = 0;

  // print values of array
  printf("printing values of array:\n");
  for (i = 0; i < 10; i++){
    printf("arr[%d] = %d \n", i, arr[i]);
  }

  // separate array
  int sarr[10];

  // populate separate array backwards
  for (i = 0; i < 10; i++){
    *(sarr + 9 - i) = *(arr + i); 
  }

  // print values of separate array
  printf("\nprinting values of second array:\n");
  for (i = 0; i < 10; i++){
    printf("sarr[%d] = %d \n", i, *(sarr + i));
  }
  return 0;
}