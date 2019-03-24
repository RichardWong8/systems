//Richard Wong & Jason Kim
//System Level Programming -- Pd.5
//Work#06 -- Con-struct-ion
//10-3-18

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

struct dex {int num; char pokemon[64];};
char* poke[] = {"Bulbasaur", "Ivysaur", "Venusaur", "Charmander", "Charmeleon", "Charizard", "Squirtle", "Wartortle", "Blastoise"};

struct dex example() {
  struct dex ex;
  int a = rand()%9;
  strcpy(ex.pokemon, poke[a]);
  ex.num = (a+1);
  return ex;
}

int print(struct dex poke) {
  printf("Dex#%d: ", poke.num);
  printf("%s\n", poke.pokemon);
  return 0;
}

int modify(struct dex *poke, int n, char *p){
  poke->num = n;
  strcpy(poke->pokemon, p);
  return 0;
}

int main() {
  srand(time(NULL));
  
  struct dex poke1;
  poke1 = example();
  
  struct dex poke2;
  poke2 = example();

  struct dex poke3;
  poke3 = example();
  
  printf("Example Structs:\n");
  print(poke1);
  print(poke2);
  print(poke3);

  modify(&poke1, 3, "Venusaur");
  modify(&poke2, 6, "Charizard");
  modify(&poke3, 9, "Blastoise");
  
  printf("After Modifications:\n");
  print(poke1);
  print(poke2);
  print(poke3);
  
  return 0;
}
