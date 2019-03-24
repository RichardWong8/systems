#ifndef LINKED_H
#define LINKED_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

struct song_node { char artist[100]; char song[100]; struct song_node *next; };

void print_node(struct song_node* n);

int compare(struct song_node* one, struct song_node* two);

int length(struct song_node* n);

void print_list(struct song_node * n);

struct song_node * insert_front(struct song_node * n, char * a, char * s);

struct song_node * insert_order(struct song_node * n, char * a, char * s);

struct song_node * find_artist_song(struct song_node * n, char * a, char * s);

struct song_node * find_artist(struct song_node * n, char * a);

struct song_node * find_rand(struct song_node * n);

struct song_node * remove_node(struct song_node *n, char* a, char*s);

struct song_node * free_list(struct song_node * n);

#endif
