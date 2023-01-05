#include "test_runner.h"


void TestAddition(){
    AssertEqual(2,2, "TestEqual 1");
}

void TestCompare(){
    Assert(2*2 == 4, "Test compare 1");
    Assert(2*2 == 5, "Test compare 2");
}



int main(){

    TestRunner runner;
    runner.RunTest(TestAddition,"TestAddition");
    runner.RunTest(TestCompare,"TestCompare");
    runner.RunTest(TestAddition,"TestAddition");

    return 0;
}