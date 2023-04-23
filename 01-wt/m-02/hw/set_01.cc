#include <iostream>
#include <set>
#include <string>

using namespace std;



int main(){

    int N{0};
    cin >> N;
    string word;
    set<string> words;
    while (N--){
        cin >> word;
        words.insert(word);
    }
    cout << words.size();


}