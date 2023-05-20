#include <forward_list>
#include <list>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
//#include "../test_runner.h"
#include <random>
#include <unordered_set>


int main(){
    std::list<int> lst;
    std::unordered_set<int> numbers;
    std::map<int,int> data;
    int q{};
    std::cin >> q;
    while (q--){
        int first,second;
        std::cin >> first >> second;
        if (!numbers.count(second)) {
            lst.push_back(first);
            numbers.insert(first);
        } else {
            auto pos = std::find(begin(lst),end(lst),second);
            lst.insert(pos,first);
            numbers.insert(first);
        }

    }
    for (auto & s: lst) {
        std::cout << s << " ";
    }
}
