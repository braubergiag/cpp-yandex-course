#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
// #include "test_runner.h"


using namespace std;
using std::vector;
void PrintVectorPart(const vector<int>& numbers){
    auto it = find_if(numbers.begin(), numbers.end(),[](const auto & number){
         return number < 0;
    });
    bool first{true};
    while (it != numbers.begin()){
        --it;
        if (!first) {
            cout << " ";
        }
        first = false;
        cout <<  *it;
    }


}

#if 0

void Test_1(){
      
    AssertEqual(PrintVectorPart({6, 1, 8, -5, 4}),"8 1 6","{6, 1, 8, -5, 4}");
    AssertEqual(PrintVectorPart({{6, 1, 8, 5, 4}}),"4 5 8 1 6","{6, 1, 8, 5, 4}");
    AssertEqual(PrintVectorPart({{-6, 1, 8, 5, 4}}),"","{6, 1, 8, 5, 4}");
    
}

void TestAll(){
    TestRunner runner;
    runner.RunTest(Test_1, "Test1");

}

#endif 
int main(){
    // TestAll();
    #if 1
      PrintVectorPart({6, 1, 8, -5, 4});
        cout << endl;
        PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
        cout << endl;
        PrintVectorPart({6, 1, 8, 5, 4});
        cout << endl;
        return 0;

#endif
}