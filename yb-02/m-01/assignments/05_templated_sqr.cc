#include <iostream>
#include <tuple>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include "07_containers_os.h"


using namespace std;


template <typename T> 
vector<T> Sqr(const vector<T>& v);

template <typename Key,typename Value>
map<Key,Value> Sqr(const map<Key,Value> & m);

template <typename First, typename Second>
pair<First,Second> Sqr(const pair<First,Second> & p);



template <typename T>
 T Sqr(const T & x);


template <typename T>
T Sqr(const T & x) {
    return x * x;
}


template <typename T>
vector<T> Sqr(const vector<T>& v){
    vector<T> sqr_v;
    transform(v.begin(),v.end(),back_inserter(sqr_v),
    [](const auto & el) {
        return Sqr(el);
    });
    return sqr_v;


}

template <typename First, typename Second>
pair<First,Second> Sqr(const pair<First,Second> & p){
    return make_pair<First,Second>(Sqr(p.first),Sqr(p.second));
}



template <typename Key,typename Value>
map<Key,Value> Sqr(const map<Key,Value> & m){
    map<Key,Value> sqr_m;
    transform(m.begin(),m.end(),inserter(sqr_m,sqr_m.begin()),
    [](const auto & el ){
        auto [key,value] = el;
        return make_pair(key,Sqr(value));
    });

    return sqr_m;
}


int main(){

    vector<map<int,int>> v = {{{1, 2}},{{3,4}}};
    cout << "vector:";
    for (auto x : Sqr(v)) {
    cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
    {4, {2, 2}},
    {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
    cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }



    return 0;
}