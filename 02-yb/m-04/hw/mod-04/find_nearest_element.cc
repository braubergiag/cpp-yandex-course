#include <vector>
#include <iostream>
#include <algorithm>
 #include "test_runner.h"
#include <set>
using namespace std;

set<int>::const_iterator FindNearestElement(const set<int> & elements, int border){
    if (elements.empty()) return end(elements);
    auto lb = elements.lower_bound(border);
    if (lb == end(elements)) {
        return prev(lb);
    } else if (lb != begin(elements) && (abs(*prev(lb) - border) <= abs(*lb - border))) {
        return prev(lb);
    } else return lb;

}
#if 1
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


void test_border_is_largest_element_in_range(){
    set<int> numbers = {1, 4, 6};
    ASSERT_EQUAL(*FindNearestElement(numbers,8),6);
    ASSERT_EQUAL(*FindNearestElement(numbers,6),6);
}
void test_border_is_smallest_element_in_range(){
    set<int> numbers {1,4,6};
    ASSERT_EQUAL(*FindNearestElement(numbers,-2),1);
    ASSERT_EQUAL(*FindNearestElement(numbers,1),1);

}
void test_border_in_the_middle_of_range(){
    set<int> numbers {1,4,6};
    ASSERT_EQUAL(*FindNearestElement(numbers,2),1);
    ASSERT_EQUAL(*FindNearestElement(numbers,3),4);

}
int main(){

#if 1
    TestRunner tr;
    RUN_TEST(tr, test_border_is_largest_element_in_range);
    RUN_TEST(tr, test_border_is_smallest_element_in_range);
    RUN_TEST(tr, test_border_in_the_middle_of_range);
    RUN_TEST(tr,test_1);
    RUN_TEST(tr,test_empty);
#endif 

}