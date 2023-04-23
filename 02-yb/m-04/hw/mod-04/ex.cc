#include <map>
#include <iostream>


using namespace std;

int main(){




    std::map<int,string> m;
    m[10] = "hello";
    auto it = prev(m.lower_bound(8));
    prev(it);
    std::cout << it-> first << "\n";


}