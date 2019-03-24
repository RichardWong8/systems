#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "linked.h"

void print_node(struct song_node* n) {
  printf("%s: %s\n",n -> artist, n -> song);
}

int compare(struct song_node* one, struct song_node* two){
  char a[200] = "hello";
  char b[200] = "hello";
  strcpy(a,one->artist);
  strcat(a,one->song);
  strcpy(b,two->artist);
  strcat(b,two->song);
  return strcmp(a,b);
  return 0;
}

int length(struct song_node* n) {
  int c = 0;
  while (n) {
    c++;
    n = n -> next;
  }
  return c;
}

void print_list(struct song_node * n) {
  printf("| ");
  while(n) {
    printf("%s: %s | ",n -> artist, n -> song);
    n = n -> next;
  }
  printf("\n");
}

struct song_node * insert_front(struct song_node * n, char * a, char * s) {
  struct song_node* new = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(new->artist, a);
  strcpy(new->song, s);
  new -> next = n;
  return new;
}

struct song_node * insert_order(struct song_node * n, char * a, char * s) {
  struct song_node* new = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(new->artist, a);
  strcpy(new->song, s);
  struct song_node* temp = n;
  struct song_node* prev;
  if (temp == NULL) {
    return insert_front(n,a,s);
  }
  if (temp && compare(new,temp) < 0) {
    return insert_front(n,a,s);
  }
  while (temp && compare(new,temp) > 0) {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL) {
    prev->next = new;
    new->next = temp;
    return n;
  }
  new->next = prev->next;
  prev->next = new;
  return n;
}

struct song_node * find_artist_song(struct song_node * n, char * a, char * s) {
  struct song_node* new = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(new->artist, a);
  strcpy(new->song, s);
  struct song_node* temp = n;
  while(temp) {
    if (compare(new,temp) == 0) {
      printf("Song Found!\n");
      return temp;
    }
    temp = temp->next;
  }
  printf("Song Not Found!\n");
  return temp;
}

struct song_node * find_artist(struct song_node * n, char * a) {
  struct song_node* temp = n;
  while(temp) {
    if (strcmp(a, temp->artist) == 0) {
      printf("Artist Found!\n");
      return temp;
    }
    temp = temp->next;
  }
  printf("Artist Not Found!\n");
  return temp;
}

struct song_node * find_rand(struct song_node * n) {
  int counter = 0;
  int limit = rand() % length(n);
  while(counter < limit) {
    n = n->next;
    counter++;
  }
  if (n != NULL) {
    printf("Random Song Found!\n");
    return n;
  }
  printf("Random Song Not Found!\n");
  return n;
}

struct song_node * remove_node(struct song_node *n, char* a, char*s) {
  struct song_node* new = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(new->artist, a);
  strcpy(new->song, s);
  if (n == NULL) {
    printf("Song Not Found!\n");
    return n;
  }
  if (compare(n,new) == 0 && length(n) == 1) {
    printf("Song Removed!\n");
    return NULL;
  }
  if (compare(n,new) == 0){
    n = n->next;
    printf("Song Removed!\n");
    return n;
  }
  struct song_node* temp = n;
  struct song_node* prev;
  while (temp && compare(new,temp) != 0) {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL) {
    printf("Song Not Found!\n");
    return n;
  }
  if (temp->next == NULL) {
    prev->next = NULL;
    printf("Song Removed!\n");
    return n;
  }
  prev->next = temp->next;
  printf("Song Removed!\n");
  return n;
}

struct song_node * free_list(struct song_node * n) {
  while (n) {
    struct song_node * temp = n->next;
    free(n);
    n = temp;
  }
  return NULL;
}

