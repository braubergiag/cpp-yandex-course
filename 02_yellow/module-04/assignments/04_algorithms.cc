#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <string>
#include "test_runner.h"

using namespace std;
using std::vector;


bool f(int i){

    return i % 2 == 0;
}

bool isOdd(int i) {return i % 2 == 1;}


int main() {

{    set<int> s = {1,2,3,4,5,6 };
    vector<int> v;
    remove_copy_if(s.begin(),s.end(),back_inserter(v),f);
    cout << "1.\t" << v << endl;
}


{

    set<int> s = {1,2,3,4,5,6 };
    vector<int> v;
    remove_copy(s.begin(),s.end(),back_inserter(v),2);
    cout << "2.\t" <<  v << endl;
}
{

    set<int> s = {1,2,3,4,5,6 };
    vector<int> v;
    remove_copy_if(s.begin(),s.end(),back_inserter(v),[](int i){
        return f(i);
    });
    cout << "3.\t" <<  v << endl;
}
{

    set<int> s = {1,2,3,4,5,6 };
    vector<int> v;
    copy_if(s.begin(),s.end(),back_inserter(v),[](int i){
        return !f(i);
    });
    cout << "4.\t" <<  v << endl;
}
{
    #if 0
    set<int> s = {1,2,3,4,5,6 };
    vector<int> v;
    auto it = partition(begin(s), end(s), f);
    copy(it, end(s), back_inserter(v));
    #endif
}
{
    #if 0

    set<int> s = {1,2,3,4,5,6 };
    vector<int> v;
    
    auto it = remove_if(begin(s), end(s), [](int x) { return !f(x); });
    copy(it, end(s), back_inserter(v));
    cout << "5.\t" <<  v << endl;
    #endif

}

{

    set<int> s = {1,2,3,4,5,6 };
    vector<int> v;
    
 
    v.assign(begin(s), end(s));
    sort(begin(v), end(v), [](int lhs, int rhs) { return f(lhs) > f(rhs); });
    auto it = partition_point(begin(v), end(v), f); v.erase(begin(v), it);
    cout << "5.\t" << v << endl;

}


{
     std::vector<int> foo {1,2,3,4,5,6,7,8,9};
    std::vector<int> odd;

    auto it =  std::partition (foo.begin(),foo.end(),isOdd);
    odd.assign(foo.begin(),it);
    cout << odd << endl;
    

}





  return 0;
}