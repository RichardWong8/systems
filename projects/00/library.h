#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "linked.h"

void add(struct song_node *library[27], char *a, char *s);

struct song_node * search_song(struct song_node *library[27], char *a, char *s);

struct song_node * search_artist(struct song_node *library[27], char *a);

void print_letter(struct song_node *library[27], char c);

void print_artist(struct song_node *library[27], char *a);

void print_library(struct song_node *library[27]);

void shuffle(struct song_node *library[27]);

void delete_song(struct song_node *library[27], char *a, char *s);

void delete_all(struct song_node *library[27]);

#endif

