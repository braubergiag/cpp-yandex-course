#include <iostream>
#include <limits>
#include <vector>

    using namespace std;


void example_1(){

    std::cout << std::numeric_limits<int>::max() << " " << std::numeric_limits<int>::min() << "\n";

}

void examples_2(){

    vector<int> tempatures = {-6,-5,5};

    int sum{0};
    for (auto t : tempatures){
        sum += t;
    }
    std::cout << sum / tempatures.size() << "\n";

}



void example_3(){

    int a = 2'000'000'000;
    int b = 1'000'000'000;

    std::cout << (a + b) / 2 << endl;
    std::cout << (-1 < 1u) << endl;


}
void example_4(){


    vector<int> v{4,3,2,2,1};

    for (size_t k = v.size(); k > 0; --k){
        size_t i = k - 1;
        cout << v[i] << " ";
    }
}
int main(){

    // example_4();
    std::cout << sizeof(long long) << "\n";
    cout << numeric_limits<long long>::max() << " " << numeric_limits<int64_t>::max() << "\n";

}