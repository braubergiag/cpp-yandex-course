#include <iostream>
#include <tuple>
#include <vector>
#include <map>
#include <utility>
using namespace std;



template <typename Key, typename Value>
Value& GetRefStrict(map<Key,Value> & m,const Key & key);



template <typename Key, typename Value>
Value& GetRefStrict(map<Key,Value> & m,const Key & key){
    if (m.count(key)) return m.at(key);

    throw runtime_error("Element doesn't exist.");
}


int main(){

    map<int, string> m = {{0, "value"}};
    try {
        string& item = GetRefStrict(m, 1);
        item = "newvalue";
        cout << m[0] << endl; // выведет newvalue

    } catch (exception & e){
        cout << e.what() << endl; 
    }



    return 0;
}