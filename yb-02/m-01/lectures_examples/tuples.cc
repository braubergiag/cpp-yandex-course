#include <iostream>
#include <tuple>



using namespace std;

int main(){

    std::tuple t(10,"Igor", true);
    std::cout << get<1>(t) << "\n";

}






