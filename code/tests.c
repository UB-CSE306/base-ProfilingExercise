#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "CUnit.h"
#include "Basic.h"
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
  CU_ASSERT_TRUE(arrayEqual(expected,actual, 27));
}

void runSlowTest(char * filename, int * expected) {
  int * actual = letterCountsSlow(filename);
  CU_ASSERT_TRUE(arrayEqual(expected,actual, 27));
}

void test_01(void) { int input[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; runFastTest("../data/file01", input); }
void test_02(void) { int input[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; runSlowTest("../data/file01", input); }

int init_suite1(void) { return 0; }    /* The suite initialization function. */
int clean_suite1(void) { return 0; }   /* The suite cleanup function. */

/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int main()
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry()) { return CU_get_error(); }

   /* add a suite to the registry */
   pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   if (
          (NULL == CU_add_test(pSuite, "file01 fast", test_01))
       || (NULL == CU_add_test(pSuite, "file01 slow", test_02))
      )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}
