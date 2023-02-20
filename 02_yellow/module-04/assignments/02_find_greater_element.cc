#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#if NDEBUG
#include "test_runner.h"
#endif

using namespace std;
using std::vector;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border){
    vector<T> result;
    auto it = upper_bound(elements.begin(),elements.end(), border);

    while (it != elements.end()){
        result.emplace_back(*it);
        ++it;
    }
    return result;

}

int main() {
  for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
    cout << x << " ";
  }
  cout << endl;
  
  string to_find = "Python";
  cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
  return 0;
}