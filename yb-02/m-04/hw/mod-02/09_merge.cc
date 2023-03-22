#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include "test_runner.h"
using namespace std;


template <typename RandomIt>
void MergeSort(RandomIt range_begin,RandomIt range_end){
    auto size = range_end - range_begin;
    if ( size < 3 ) return;

    
    
    vector<typename RandomIt::value_type> elements(range_begin,range_end);
    auto first_third = elements.begin() + size / 3;
    auto second_third = first_third + size / 3;

    MergeSort(elements.begin(),first_third);
    MergeSort(first_third,second_third);
    MergeSort(second_third,elements.end());

    vector<typename RandomIt::value_type> v;
    merge(elements.begin(),first_third,first_third,second_third,back_inserter(v));
    merge(v.begin(),v.end(),second_third,elements.end(),range_begin);
}


int main(){

  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1,4};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;


}