#include <string>
#include <vector>
using namespace std;
#define TOKENPASTE_1(x,y) x ## y
#define TOKENPASTE_2(x,y) TOKENPASTE_1(x,y)

#define UNIQ_ID TOKENPASTE_2(var_,__LINE__)
int main() {

  int UNIQ_ID = 0;

  string UNIQ_ID = "hello";
  vector<string> UNIQ_ID = {"hello", "world"};
  vector<int> UNIQ_ID = {1, 2, 3, 4};
}