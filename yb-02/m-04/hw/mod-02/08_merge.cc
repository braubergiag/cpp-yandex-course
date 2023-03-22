#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include "test_runner.h"
using namespace std;


template <typename RandomIt>
void MergeSort(RandomIt range_begin,RandomIt range_end){
    auto size = range_end - range_begin;
    if ( size < 2 ) return;

    vector<typename RandomIt::value_type>   v1(range_begin,range_begin + size / 2),
                                            v2(range_begin + size / 2, range_end);



    MergeSort(v1.begin(), v1.end());
    MergeSort(v2.begin(), v2.end());
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),range_begin);
}


int main(){

  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;


}