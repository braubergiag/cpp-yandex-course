#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

template <typename It>
void PrintRange(It begin, It end){
    for (auto it = begin; it != end; ++it)
    {
        cout << *it << " ";

    }
    cout << endl;
    
}



int main(){


    vector<string> langs {"Java","Java","C#","C#","Python","Java","C++"};

    auto it = unique(langs.begin(), langs.end());
    cout << langs.size() << "\n";
    langs.erase(it,langs.end());
    cout << langs.size() << "\n";
    PrintRange(langs.begin(),langs.end());



}