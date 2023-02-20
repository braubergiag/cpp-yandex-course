#include <iostream>






template <typename T>
T Square(T t){
    return t * t;
}


int main(){

    std::cout << Square(2) << std::endl;
    std::cout << Square(2.5) << std::endl;

    return 0;
}