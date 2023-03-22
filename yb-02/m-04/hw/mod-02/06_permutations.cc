#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include "test_runner.h"
using namespace std;

void PrintPermuatations(int n){
    std::vector<int> v(n);
    std::iota(v.rbegin(), v.rend(),1);
    do {
        for (auto &&i : v)
        {
            cout << i << " ";
        }
        cout << "\n";
        
    } while (prev_permutation(v.begin(),v.end()));
}


int main(){

    int n = 0;
    std::cin >> n;
    PrintPermuatations(n);


}