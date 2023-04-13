#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <criterion/criterion.h>
#include "counts.h"

// assumption: both arrays are of the same size
bool arrayEqual(int * a, int * b, int size) {
  for (int i=0; i<size; i++) {
    if (a[i] != b[i]) {
	return false;
      }
  }
  return true;
}


void runFastTest(char * filename, int * expected) {
  int * actual = letterCounts(filename);
  cr_assert(arrayEqual(expected,actual, 27));
}

void runSlowTest(char * filename, int * expected) {
  int * actual = letterCountsSlow(filename);
  cr_assert(arrayEqual(expected,actual, 27));
}

Test(exercise, test01) { int input[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; runFastTest("../data/file01", input); }
Test(exercise, test02) { int input[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; runSlowTest("../data/file01", input); }


