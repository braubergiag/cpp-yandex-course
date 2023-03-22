#include <vector>
#include <iostream>
#include <algorithm>
// #include "test_runner.h"
#include <set>
using namespace std;

set<int>::const_iterator FindNearestElement(const set<int> & elements, int border){
    if (elements.empty()) return end(elements);
    auto [lb,ub] = elements.equal_range(border);

    if (*lb == border) return lb;
    else lb = prev(lb);

    if (abs(border - *lb) <= abs(border - *ub)) return lb;
    else return ub;

}
#if 0
void test_1(){
    set<int> v{1,2,4,5,7,9,10,14,15};
    ASSERT_EQUAL(*FindNearestElement(v,0),1);
    ASSERT_EQUAL(*FindNearestElement(v,3),2);
    ASSERT_EQUAL(*FindNearestElement(v,6),5);
    ASSERT_EQUAL(*FindNearestElement(v,20),15);
    ASSERT_EQUAL(*FindNearestElement(v,13),14);
    ASSERT_EQUAL(*FindNearestElement(v,12),10);

      set<int> numbers = {1, 4, 6};
    ASSERT_EQUAL( *FindNearestElement(numbers, 0),1);
    ASSERT_EQUAL( *FindNearestElement(numbers, 3),4);
    ASSERT_EQUAL( *FindNearestElement(numbers, 5),4);
    ASSERT_EQUAL( *FindNearestElement(numbers, 6),6);
    ASSERT_EQUAL( *FindNearestElement(numbers, 100),6);




}
void test_empty(){
     set<int> v;
     ASSERT(FindNearestElement(v,2) == end(v));
}
#endif
int main(){

#if 0
    TestRunner tr;
    RUN_TEST(tr,test_1);
    RUN_TEST(tr,test_empty);
#endif 

}