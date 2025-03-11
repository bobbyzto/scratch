/* test.h
 * Include this header multiple times to implement unit tests.
 * Before inclusion define TEST_T to the type of test being used.
 * */

#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED
#include <stdlib.h>

#define TESTSUITE_IMPL(line) Test##line
#define TESTSUITE_RELAY(line) TEST_IMPL(line)
#define TESTSUITE TESTSUITE_RELAY(__LINE__)

