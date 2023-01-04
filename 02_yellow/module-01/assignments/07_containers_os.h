#include <iostream>
#include <tuple>
#include <vector>
#include <map>
#include <utility>
#include <array>
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


template <typename T, size_t size>
ostream& operator<<(ostream& os, const array<T,size> & v ){
    os << "<";
    for (const auto & el : v){
        os << el << ",";
    }
    os << ">";

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
