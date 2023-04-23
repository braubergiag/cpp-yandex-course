#include "test_runner.h"


void TestAddition(){
    ASSERT_EQUAL(2,3);
}

void TestCompare(){
    ASSERT(2*2 == 4);
    ASSERT(2*2 == 5);
}



int main(){

    TestRunner runner;
    RUN_TEST(runner,TestAddition);
    RUN_TEST(runner,TestCompare);

    return 0;
}