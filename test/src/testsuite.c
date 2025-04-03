#include <stdio.h>
#include "test.h"

#define PROJECT_NAME "testsuite"
TEST(test_can_fail)
{
    LOG_MSG("test_can_fail: \n");
    return -1;
}

int main(int argc, char **argv) {
    if(argc != 1) {
        printf("%s takes no arguments.\n", argv[0]);
        return 1;
    }
    
    Test test_created;
    test_created.result = RUN_TEST(test_can_fail);

    return (PASS_OR_FAIL(test_created));
}
