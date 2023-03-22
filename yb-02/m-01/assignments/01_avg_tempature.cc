#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using std::vector;

int64_t calculate_avg(const vector<int> & v){
    return std::accumulate(v.begin(),v.end(),0ll) / static_cast<int>(v.size());

}


vector<int> find_above_average_days(const vector<int> & tempatures, int64_t avg_tempature){

    vector<int> above_average;
    for (size_t i = 0, sz = tempatures.size(); i < sz; i++)
    {
        if (tempatures.at(i) > avg_tempature) {
            above_average.emplace_back(i);
        }
    }

}


int main(){


    size_t K{0};
    std::cin >> K;
    
    std::vector<int> tempatures(K,0);

    std::transform(tempatures.begin(), tempatures.end(),tempatures.begin(),
        [](auto & temp) {
            std::cin >> temp;
            return temp;
        }
    );

    vector<int> above_average = find_above_average_days(tempatures,calculate_avg(tempatures));
    
    std::cout << above_average.size() << "\n";
    for (auto &&temp_idx : above_average)
    {
        std::cout << temp_idx << " ";
    }
    

    
    
}