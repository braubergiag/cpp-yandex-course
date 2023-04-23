#include <vector>
#include <iostream>
#include <algorithm>
#include "test_runner.h"
using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindSegment(
    RandomIt range_begin, RandomIt range_end, int left, int right) {

    return {upper_bound(range_begin, range_end, left - 1), lower_bound(range_begin, range_end, right + 1)};
        // return {lower_bound(range_begin,range_end,left - 1), prev(lower_bound(range_begin,range_end,right + 1))};
        // return {lower_bound(range_begin,range_end,left - 1), upper_bound(range_begin,range_end,right)};
}

int main(){



    vector<int> v{1,2,4,5,6,7,8,9,10,14,15};
    auto p = FindSegment(begin(v),end(v),3,10);
    cout << *p.first << " " << *p.second <<  endl;


}