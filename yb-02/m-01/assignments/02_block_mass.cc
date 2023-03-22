#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using std::vector;


int main(){


    size_t amount{0}, density{0};

    std::cin >> amount >> density;
    
    uint64_t overall_mass{0};
    for (size_t i = 0; i < amount; i++)
    {
        uint64_t w{0},h{0},d{0};
        std::cin >> w >> h >> d;

        overall_mass += density * (w * h * d);

    }

    std::cout << overall_mass << "\n";
    



    
    
}