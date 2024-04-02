#include <stdio.h>
#include <stdlib.h>
#include "counts.h"

int main(int argc, char * argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Correct usage: letterCounts <name of data file>");
        exit(EXIT_FAILURE);
    }
  int * countArray;
  countArray = letterCounts(argv[1]);
  printCounts(countArray, "letterCounts", argv[1]);
  printf("\n");
  countArray = letterCountsSlow(argv[1]);
  printCounts(countArray, "letterCountsSlow", argv[1]);
  printf("\n");
  countArray = letterCountsGlacial(argv[1]);
  printCounts(countArray, "letterCountsGlacial", argv[1]);
  exit(EXIT_SUCCESS);
}
