#include <stdio.h>
#include <stdlib.h>

int main(void) {
  unsigned int num = 2200000000;
  char *num_p = &num;

  //print int
  printf("int in decimal %u \n", num);
  printf("int in hex: %x \n\n", num);

  //print individual bytes 
  int i;
  for(i = 0; i < sizeof(num); i++){
    printf("individual byte: %hhx \n", *num_p);
    num_p ++ ;
  }
  num_p = &num;

  //increment bytes by 1
  printf("\nincrement bytes by 1\n");
  for(i = 0; i < sizeof(num); i++){
    (*num_p)++;
    num_p++;
    printf("decimal value: %u ", num);
    printf("hex value: %x \n", num);
  }
  num_p = &num;
  //increment bytes by 16
  printf("\nincrement bytes by 16\n");
  for(i = 0; i < sizeof(num); i++){
    (*num_p) += 16;
    num_p++;
    printf("decimal value: %u ", num);
    printf("hex value: %x \n", num);
  }

  return 0;
}