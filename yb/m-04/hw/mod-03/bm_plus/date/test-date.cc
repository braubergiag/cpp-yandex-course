#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <chrono>
#include <sstream>
#include <ctime>
#include <map>
using namespace std;
using namespace chrono;

#include "date.h"
void testing_date(){



    std::tm tm_1 = {};
    std::tm tm_2 = {};
    std::stringstream ss("2002-01-02");
    strptime("1700-01-01", "%Y-%m-%d", &tm_1);
    strptime("2099-12-31", "%Y-%m-%d", &tm_2);
    auto tp_1 = std::mktime(&tm_1);
    auto tp_2 = std::chrono::system_clock::from_time_t(std::mktime(&tm_2));
    

        ::uint64_t timestamp_max = time_point_cast<seconds>(tp_2)
            .time_since_epoch()
            .count();
    cout << tp_1 << "\n";

}

int main(){


    Date d1(Year(2000),Month(1),Day(1));
    Date d2(Year(2000),Month(1),Day(2));
    Date d3(Year(2000),Month(1),Day(4));

    Date d4(Year(2000),Month(1),Day(5));
    Date d5(Year(2000),Month(1),Day(10));
    Date d6(Year(2000),Month(1),Day(6));


    std::map<Date,int> m;
    m[d1] = 1;
    m[d2] = 2;
    m[d3] = 3;

    double income{0};
    auto lb = m.lower_bound(d1);
    auto ub = m.lower_bound(d3);
    std::cout << lb->first << " " << ub->first << "\n";
    for (auto &&i : m)
    {
        if (i.first >= (*lb).first && i.first <= (*ub).first){
            income += i.second;

            }
    }
    std::cout << income << endl;
    

}