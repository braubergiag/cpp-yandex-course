#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <string>
#if NDEBUG
#include "test_runner.h"
#endif

using namespace std;
using std::vector;



vector<string> SplitIntoWords(const string& s){

    vector<string> words;

    auto begin = s.begin();
    auto it = find(s.begin(),s.end(),' ');
    while (it != s.end()){
      words.push_back(string(begin,it));
      begin = ++it;
      it = find(begin,s.end(),' ');

    }
    words.push_back(string(begin,s.end()));
    return words;

}


int main() {

     string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;


  return 0;
}