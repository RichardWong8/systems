int length(char *s) {
  int counter = 0;
  while(s[counter]) {
    counter++;
  }
  return counter;
}

char * copy(char *dest, char *source) {
  int i = 0;
  while(*(source+i)) {
    *(dest+i) = *(source+i);
    i++;
  }
  return dest;
}

char * catn(char *dest, char *source, int n) {
  int i = length(dest);
  int counter = 0;
  while(counter<n) {
    *(dest+i) = *(source+counter);
    i++;
    counter++;
  }
  return dest;
}

int cmp( char *s1, char *s2 )  {
  int i = 0;
  int stop;
  if (length(s1) < length(s2)){
    stop = length(s1);
  }
  else {
    stop = length(s2);
  }
  while(i <= stop){
    if (*(s1+i) < *(s2+i)) {
      return -1;
    }
    else if (*(s1+i) > *(s2+i)){
      return 1;
    }
    i++;
  }
  if (length(s1) < length(s2)){
    return -1;
  }
  else if(length(s1) > length(s2)){
    return 1;
  }
  else {
    return 0;
  }
}

char * search(char* s, char c) {
  int i = 0;
  while(*(s+i)) {
    if(*(s+i) == c) {
      return s+i;
    }
    i++;
  }
  return 0;
}
