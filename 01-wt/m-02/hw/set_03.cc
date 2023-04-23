

#include <iostream>
#include <set>
#include <string>
#include <map>
using namespace std;





#if 1
int main(){

    map<string, set<string>> synonyms;
    string command;
    int Q{};
    cin >> Q;
    while (Q--){
        std::cin >> command;
        if (command == "ADD"){
            string word_1, word_2;
            cin >> word_1 >> word_2;
            synonyms[word_1].insert(word_2);
            synonyms[word_2].insert(word_1);
        } else if (command == "COUNT"){
            string word;
            cin >> word;
            if (synonyms.count(word)) cout << synonyms[word].size() << endl;
            else cout << "0" << endl;
        } else if (command == "CHECK"){
            string word_1, word_2;
            cin >> word_1 >> word_2;
            if (synonyms.count(word_1) && synonyms[word_1].count(word_2)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    } 

}
#endif