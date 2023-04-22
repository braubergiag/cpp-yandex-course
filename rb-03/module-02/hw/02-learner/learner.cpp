#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <sstream>
using namespace std;

class Learner {
 private:
  set<string> dict;

 public:
  int Learn(const vector<string>& words) {
    int newWords = 0;
    for (const auto& word : words) {
      auto [it,succ] = dict.insert(word);
      if (succ) ++newWords;
    }
    return newWords;
  }

  vector<string> KnownWords() {
    return {dict.begin(),dict.end()};
  }
};
#if 0
int main() {
  Learner learner;
  string line;
  while (getline(cin, line)) {
    vector<string> words;
    stringstream ss(line);
    string word;
    while (ss >> word) {
      words.push_back(word);
    }
    cout << learner.Learn(words) << "\n";
  }
  cout << "=== known words ===\n";
  for (auto word : learner.KnownWords()) {
    cout << word << "\n";
  }
}
#endif