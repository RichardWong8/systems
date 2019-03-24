#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "linked.h"
#include "library.h"

int main() {
  srand(time(NULL));
  
  struct song_node * root = NULL;
  printf("LINKED LIST: \n");
  printf("insert_order() and insert_front()\n");
  root = insert_order(root, "queen","bohemian rhapsody");
  root = insert_order(root, "radiohead","creep");
  root = insert_order(root, "m83","outro");
  root = insert_order(root, "m83", "intro");
  root = insert_order(root, "radiohead", "karma police");
  root = insert_front(root, "ac/dc", "highway to hell");
  print_list(root);

  printf("length(): %d\n", length(root));
  
  printf("compare() w/ highway to hell and intro: %d\n", compare(root, (root->next)));

  printf("find_artist_song(), find_song(), find_rand()\n");
  struct song_node * BR = (struct song_node *) malloc(sizeof(struct song_node));
  BR = find_artist_song(root, "queen", "bohemian rhapsody");
  print_node(BR);

  struct song_node * M83 = (struct song_node *) malloc(sizeof(struct song_node));
  M83 = find_artist(root, "m83");
  print_node(M83);;

  struct song_node * RAND = (struct song_node *) malloc(sizeof(struct song_node));
  RAND = find_rand(root);
  print_node(RAND);

  printf("remove_node()\n");
  root = remove_node(root, "queen", "bohemian rhapsody");
  root = remove_node(root, "ac/dc", "highway to hell");
  root = remove_node(root, "radiohead", "karma police");
  root = remove_node(root, "not", "not");
  print_list(root);

  printf("free_list()\n");
  root = free_list(root);
  print_list(root);

  printf("\nLIBRARY:\n");

  struct song_node * library[27];
  for (int i = 0; i < 27; i++) {
    library[i] = NULL;
  }
  printf("add()\n");
  add(library, "queen","bohemian rhapsody");
  add(library, "radiohead","creep");
  add(library, "m83","outro");
  add(library, "m83", "intro");
  add(library, "radiohead", "karma police");
  add(library, "ac/dc", "highway to hell");
  print_library(library);

  printf("search_song(), search_artist\n");
  BR = NULL;
  BR = search_song(library, "queen", "bohemian rhapsody");
  print_node(BR);

  M83 = NULL;
  M83 = search_artist(library, "m83");
  print_node(M83);;

  printf("print_letter(), print_artist(), print_library()\n");
  print_letter(library, 'q');
  print_artist(library, "m83");
  print_library(library);

  printf("shuffle()\n");
  shuffle(library);

  printf("delete_song(), delete_all()\n");
  delete_song(library, "queen", "bohemian rhapsody");
  print_library(library);
  delete_all(library);
  print_library(library);
  
}
