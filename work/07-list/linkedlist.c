#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

void print_list(struct node * first) {
  struct node * curr = first;
  while (curr) {
    printf("%d->", curr->i);
    curr = curr->next;
  }
}

struct node * insert_front(struct node * first, int val) {
  struct node * front = (struct node *) malloc(sizeof(struct node));
  front->i = val;
  front->next = first;
  return front;
}

struct node * free_list(struct node * first) {  
  struct node * curr = first;
  while (curr) {
    struct node * next = curr->next;
    free(curr);
    curr = next;
  }
  return curr;
}