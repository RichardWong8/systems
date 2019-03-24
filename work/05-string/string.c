//Jason Kim & Richard Wong
//System Level Programming - Pd.5
//Work#05
//10-1-18

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

int main() {
  char s1[64] = "anything";
  char s2[64] = "something";

  printf("s1:[%s]\n", s1);
  printf("s2:[%s]\n", s2);

  printf("=========================\n");
  
  printf("Testing strlen(s1):\n");
  printf("Ours: %d\n", length(s1));
  printf("Standard: %d\n", (int)strlen(s1));

  printf("=========================\n");

  printf("Testing strcpy(s1,s2):\n");
  printf("Ours: [%s]\n", copy(s1,s2));
  strcpy(s1, "anything");
  printf("Standard: [%s]\n", strcpy(s1,s2));
  strcpy(s1, "anything");

  printf("=========================\n");

  printf("Testing strcatn(s1,s2):\n");
  printf("Ours: [%s]\n", catn(s1,s2,4));
  strcpy(s1, "anything");
  printf("Standard: [%s]\n", strncat(s1,s2,4));
  strcpy(s1, "anything");

  printf("=========================\n");
  
  printf("Testing strcmp(char *s1, char *s2):\n");
  printf("Ours:     a, b: %d\n", cmp("a","b"));
  printf("Standard: a, b: %d\n", strcmp("a","b"));
  printf("Ours:     c, b: %d\n", cmp("c","b"));
  printf("Standard: c, b: %d\n", strcmp("c","b"));
  printf("Ours:     apple, apple: %d\n", cmp("apple","apple"));
  printf("Standard: apple, apple: %d\n", strcmp("apple","apple"));
  printf("Ours:     applez, apple: %d\n", cmp("applez","apple"));
  printf("Standard: applez, apple: %d\n", strcmp("applez","apple"));
  printf("Ours:     apple, applez: %d\n", cmp("apple","applez"));
  printf("Standard: apple, applez: %d\n", strcmp("apple","applez"));

  printf("=========================\n");

  printf("Testing strchr(s1,'t'):\n");
  printf("Ours: %d\n", search(s1,'t'));
  printf("Standard: %d\n", strchr(s1,'t'));
  printf("Testing strchr(s1,'p'):\n");
  printf("Ours: %d\n", search(s1,'p'));
  printf("Standard: %d\n", strchr(s1,'p'));

  return 0;
}
