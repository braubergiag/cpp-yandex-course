// #include "../test_runner.h"

#include <ostream>
using namespace std;

#define PRINT_VALUES_MINE(out, x, y)   if (1) { out << (x) << endl; out << (y) << endl;} else 
#define PRINT_VALUES(out, x, y)    out << (x)  << endl << (y) << endl

#if 0
void test_1(){
  ostringstream output;
    PRINT_VALUES(output, 5, "red belt");
    ASSERT_EQUAL(output.str(), "5\nred belt\n");
}
void test_2(){
    ostringstream output;
    PRINT_VALUES(output,5 + 5,"ONE");
    ASSERT_EQUAL(output.str(),"10\nONE\n");
}
void test_3(){
    ostringstream output;
    int x{1};
    PRINT_VALUES(output,x,"ONE");
    ASSERT_EQUAL(output.str(),"1\nONE\n");
    PRINT_VALUES(output,x,"ONE");
    ASSERT_EQUAL(output.str(),"1\nONE\n");

}

void test_4(){
  bool cond{false};
  ostringstream out;
  if (cond) 
    PRINT_VALUES(out,1,1);
  else 
    PRINT_VALUES(out,0,0);
  

  ASSERT_EQUAL(out.str(),"0\n0\n");
}

void test_5(){
  {
  bool cond{false};
  ostringstream out;
  if (cond)  {PRINT_VALUES(out,1,1); }
  else PRINT_VALUES(out,0,0);
  ASSERT_EQUAL(out.str(),"0\n0\n");
  }

  {
    bool cond{true};
  ostringstream out;
  if (cond)  PRINT_VALUES(out,1,1);
  else PRINT_VALUES(out,0,0);
  ASSERT_EQUAL(out.str(),"1\n1\n");
  }
}

int main() {
  TestRunner tr;
  tr.RunTest(test_1,"PRINT_VALUES usage example");
  tr.RunTest(test_2,"PRINT_VALUES usage example");
  tr.RunTest(test_3,"PRINT_VALUES usage example");
  tr.RunTest(test_4,"PRINT_VALUES IF_ELSE usage example");
  tr.RunTest(test_5,"PRINT_VALUES IF_ELSE usage example");
   

}
#endif