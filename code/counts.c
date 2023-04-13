#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "counts.h"

int * newArray(int size) {
  int * counts = malloc(size * sizeof(* counts));
  for (int i=0; i<size; i++) {
    counts[i] = 0;
  }
  return counts;
}

int * letterCounts(char * filename) {
  int * counts = newArray(27);

  FILE *fp;
  fp = fopen(filename, "r");
  int ch = '\0';
  while ( (ch = fgetc(fp)) != EOF ) {
    if (isalpha(ch)) {
      ch = tolower(ch);
      counts[ch-'a']++;
    }
    else {
      counts[26]++;
    }
  }
  fclose(fp);
  return counts;
}

int * letterCountsSlow(char * filename) {
  int * counts = newArray(27);

  FILE *fp;
  fp = fopen(filename, "r");
  int ch = '\0';
  while ( (ch = fgetc(fp)) != EOF ) {
    if (isalpha(ch)) {
      ch = (tolower(ch));
      int index = 'a';
      while (index < ch) {
	index++;
      }
      counts[index-'a']++;
    }
    else {
      counts[26]++;
    }
  }
  fclose(fp);
  return counts;
}

void printCounts(int * counts) {
  int i;
  for (i='a'; i<='z'; i++) {
    printf("counts['%c'] is %4d\n",i,counts[i-'a']);
  }
  printf("counts[other] is %4d\n",counts[i-'a']);
  printf("print\n");
}
