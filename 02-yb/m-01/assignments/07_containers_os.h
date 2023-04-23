#include <iostream>
#include <tuple>
#include <vector>
#include <map>
#include <utility>
#include <array>
#include <sstream>
using namespace std;



template <typename Collection>
std::string Printer(const Collection & collection, char sep){

    stringstream ss;
    bool first{true};
    for (const auto & el: collection){
        if (!first) {
            ss << sep;
        }
        first = false;
        ss << el;
    }


    return ss.str();
    
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T> & v ){
   return os << "[" << Printer(v,',') << "]";
}


template <typename T, size_t size>
ostream& operator<<(ostream& os, const array<T,size> & a ){
    return os << "<" << Printer(a,',') << ">";
}

template <typename First, typename Second>
ostream& operator<<(ostream & os, const pair<First,Second> p){
    return os << "(" << p.first << "," << p.second << ")";
}


template <typename Key, typename Value>
ostream& operator<<(ostream & os, const map<Key,Value> & m){
    return os << "{" << Printer(m,',') << "}";

}
