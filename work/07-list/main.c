#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int main(){
  struct node * front = NULL;
  printf("Empty linked list: \n");
  print_list(front);

  int i;
  for (i = 0; i < 10; i++){
    printf("Insert %d to front: ", i);
    front = insert_front(front, i);
    print_list(front);
    printf("\n");
  }

  printf("Freeing list: ");
  front = free_list(front);
  print_list(front);
}