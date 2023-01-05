#include "containers_os.h"
#include <sstream>



template <typename U , typename V>
void AssertEqual(const U & u, const V & v){
    stringstream ss;
    if (u != v){
        ss << u << " != " << v;
        throw runtime_error(ss.str());
    }

}

void Assert(bool val){
    if (!val){
        throw runtime_error("failed.");
    }
}

class TestRunner {

public:
    TestRunner() = default;


    template <typename Function>
    void RunTest(Function test,const string& hint){
        try
        {
            test();
            ++passed_tests_;
        }
        catch(const std::exception& e)
        {
            std::cerr << hint << " " << e.what() << '\n';
            ++failed_tests_;
        }
        
    }

    ~TestRunner(){
        PrintStatistics();
    }

    void PrintStatistics(){
        cout << "=================\n"
             << "Test passed: " << passed_tests_ << '\n'
             << "Test failed: " << failed_tests_ << '\n';
        
    }



private:
    int failed_tests_{0};
    int passed_tests_{0};


};



void TestAddition(){
    AssertEqual(1,2);
}

void TestCompare(){
    Assert(2*2 == 4);
    Assert(2*2 == 5);
}


int main(){

    TestRunner runner;
    runner.RunTest(TestAddition,"TestAddition");
    runner.RunTest(TestCompare,"TestCompare");

    return 0;
}