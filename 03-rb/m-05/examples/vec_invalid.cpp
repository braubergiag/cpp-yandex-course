#include <vector>
#include <iostream>


int main() {

    using namespace std;

    vector<int> v {1,2,3};

    auto &first = v[0];
    cout << first << endl;

    v.push_back(23);
    cout << first << endl;

    return 0;
}