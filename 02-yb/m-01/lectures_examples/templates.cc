#include <iostream>
#include <tuple>
#include <vector>
#include <map>
#include <utility>
#include <array>
using namespace std;

#include "../assignments/07_containers_os.h"

int main(){


    vector<int> v{1,2,3};
    map<int,int> m{{1,2},{2,3},{4,5}};
    array<int,5> ar{0,2,3,4,5};
    vector<pair<string,int>> vv{{"Igor",26},{"Kate",28}};
    cout << vv;

}






