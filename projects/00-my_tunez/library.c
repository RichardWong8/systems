#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "linked.h"
#include "library.h"

void add(struct song_node *library[27], char *a, char *s) {
  int index = a[0] - 'a';
  if (index < 0 || index > 25) {
    index = 26;
  }
  library[index] = insert_order(library[index], a, s);
}

struct song_node * search_song(struct song_node *library[27], char *a, char *s){
  int index = a[0] - 'a';
  if (index < 0 || index > 25) {
    index = 26;
  }
  return find_artist_song(library[index], a, s);
}

struct song_node * search_artist(struct song_node *library[27], char *a){
  int index = a[0] - 'a';
  if (index < 0 || index > 25) {
    index = 26;
  }
  return find_artist(library[index], a);
}

void print_letter(struct song_node *library[27], char c){
  int index = c - 'a';
  if (index < 0 || index > 25) {
    index = 26;
  }
  if(library[index]) {
    printf("Letter Found!\n");
  }
  else{
    printf("Letter Not Found!\n");
  }
  print_list(library[index]);
}

void print_artist(struct song_node *library[27], char *a){
  struct song_node * temp = search_artist(library, a);
  printf("| ");
  while (temp && strcmp(temp -> artist, a) == 0) {
    printf("%s: %s | ", temp->artist, temp->song);
    temp = temp -> next;
  }
  printf("\n");
}

void print_library(struct song_node *library[27]){
  int counter = 0;
  for (int i = 0; i < 27; i++) {
    if (library[i]) {
      print_list(library[i]);
      counter++;
    }
  }
  if (counter == 0) {
    printf("|\n");
  }
}

void shuffle(struct song_node *library[27]) {
  int i = 0;
  while (i<27) {
    if (library[i]) {
      i=100;
    }
    i++;
  }
  if (i != 101) {
    printf("No Songs Found!\n");
    return;
  }
  int counter = 3;
  while (counter) {
    int r = rand()%27;
    if (library[r]) {
      print_node(find_rand(library[r]));
      counter--;
    }
  }
}

void delete_song(struct song_node *library[27], char *a, char *s){
  int index = a[0] - 'a';
  if (index < 0 || index > 25) {
    index = 26;
  }
  library[index] = remove_node(library[index], a, s);
}

void delete_all(struct song_node *library[27]){
  for (int i = 0; i < 27; i++) {
    free_list(library[i]);
    library[i] = NULL;
  }
}
