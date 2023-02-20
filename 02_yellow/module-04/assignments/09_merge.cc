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

    
    auto first_third = range_begin + size / 3;
    auto second_third = first_third + size / 3;

    vector<typename RandomIt::value_type> v;
    MergeSort(range_begin,first_third);
    MergeSort(first_third,second_third);
    MergeSort(second_third,range_end);

    merge(range_begin,first_third,first_third,second_third,back_inserter(v));
    merge(v.begin(),v.end(),second_third,range_end,range_begin);
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