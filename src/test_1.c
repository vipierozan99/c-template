#include <munit.h>

#if defined(_MSC_VER)
#pragma warning(disable : 4127)
#endif

static void *test_compare_setup(const MunitParameter params[],
                                void *user_data) {}

static void test_compare_tear_down(void *fixture) {}

/* Tests are functions that return void, and take a single void*
 * parameter.  We'll get to what that parameter is later. */
static MunitResult test_always_false(const MunitParameter params[],
                                     void *data) {
  munit_assert(0 == 1);
  return MUNIT_OK;
}

/* Creating a test suite is pretty simple.  First, you'll need an
 * array of tests: */
static MunitTest test_suite_tests[] = {
    {(char *)"/my_test", test_always_false, test_compare_setup,
     test_compare_tear_down, MUNIT_TEST_OPTION_NONE, NULL},
    // All nulls means the end of the array
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}};

static const MunitSuite test_suite = {(char *)"", test_suite_tests, NULL, 1,
                                      MUNIT_SUITE_OPTION_NONE};

#include <stdlib.h>
int main(int argc, char *argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
  /* Finally, we'll actually run our test suite!  That second argument
   * is the user_data parameter which will be passed either to the
   * test or (if provided) the fixture setup function. */
  return munit_suite_main(&test_suite, (void *)"µnit", argc, argv);
}