/* test.h
 * Include this header multiple times to implement unit tests.
 * Before inclusion define TEST_T to the type of test being used.
 * */

#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED
#include <stdlib.h>

#define LOG_MSG(fmt, ...) \
  fprintf(stdout, fmt, ##__VA_ARGS__)

#define TEST_CODE_FAILURE -1
#define TEST_CODE_SUCCESS  0
#define PASS_OR_FAIL(test) \
    test.result == 0 ? TEST_CODE_SUCCESS : TEST_CODE_FAILURE

#define TESTSUITE_CLASS_FINAL(line) Test##line
#define TESTSUITE_CLASS_RELAY(line) TESTSUITE_CLASS_FINAL(line) 
#define TESTSUITE_CLASS TESTSUITE_CLASS_RELAY(__LINE__)

#define TESTSUITE_IMPL(line) Test##line
#define TESTSUITE_IMPL_RELAY(line) TEST_IMPL(line)
#define TESTSUITE TESTSUITE_IMPL_RELAY(__LINE__)

typedef struct Test Test;
struct Test 
{ 
    void (*run)(const char * name); 
    int result; 
};
typedef struct 
{
    char * beg;
    char * end;
} TestPool;

void * alloc_test(
    TestPool * t, ptrdiff_t size, 
    ptrdiff_t align, ptrdiff_t count)
{
    ptrdiff_t padding = -(uintptr_t)t->beg & (align - 1);
    ptrdiff_t available = t->end - t->beg - padding;
    if (available < 0 || count > available/size)
    {
        abort(); // out of mem.
    }
    void * p = t->beg + padding;
    t->beg += padding + (count * size);
    return memset(p, 0, count, size);
}

#define DECLARE_MODULE_TEST \
static int num_tests = 0;
TestPool test_pool;

#define ADD_TEST(test_name) \



#define TEST(test_name) \
int run_##test_name(); \
int run_##test_name()

#define RUN_TEST(test_name) \
run_##test_name();

#endif // !TEST_H_INCLUDED
