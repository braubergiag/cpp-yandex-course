#include <iostream>
#include <tuple>
#include <vector>
#include <map>
#include <utility>
using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T> & v ){
    os << "[";
    for (const auto & el : v){
        os << el << ",";
    }
    os << "]";

    return os;
}


template <typename First, typename Second>
ostream& operator<<(ostream & os, const pair<First,Second> p){
    os << "(" << p.first << "," << p.second << ")";
    return os;
}


template <typename Key, typename Value>
ostream& operator<<(ostream & os, const map<Key,Value> & m){
    os << "{";
    for (const auto & el : m){
        os  << el  << ",";
    }
    os << "}";

    return os;
}

template <typename T>
T Max(const T& a, const T& b){
    return a > b ? a : b;
}


int main(){

#if 0
    vector<int> v {12,3,3};
    cout << v << endl;

    map<int,int> m {{1,2},{3,4}};
    cout << m << endl;
#endif
    cout << Max<int>(2,3.4);

}






