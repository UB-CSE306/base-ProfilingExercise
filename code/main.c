#include <stdio.h>
#include <stdlib.h>
#include "counts.h"

int main() {
  int * countArray;
  countArray = letterCounts("../data/file00");
  printCounts(countArray);
  countArray = letterCountsSlow("../data/file00");
  printCounts(countArray);
  return 0;
}
