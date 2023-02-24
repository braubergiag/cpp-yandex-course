#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <chrono>
#include "test_runner.h"
#include "date.h"
#include <sstream>
#include <ctime>
#include <map>
using namespace std::chrono;


class BudgetManager {
private:
    static constexpr int first_day_timestamp = 10'956;

public:
        BudgetManager()  {
            earnings_.resize(50'000);
            std::fill(begin(earnings_),end(earnings_),0.0);
        }


    void Earn(const std::string & date_from,const std::string & date_to, int earning) {
        auto tp_from = ParseDateToTimestamp(date_from);
        auto tp_to = ParseDateToTimestamp(date_to);

        double earning_by_each_day = earning / ((tp_to - tp_from) + 1);
        for (int timestamp = tp_from; timestamp <= tp_to; ++timestamp) {
            earnings_[timestamp - first_day_timestamp] += earning_by_each_day;
        }
    }
    double ComputeIncome(const std::string & date_from,const std::string & date_to) {
        auto tp_from = ParseDateToTimestamp(date_from) - first_day_timestamp;
        auto tp_to = ParseDateToTimestamp(date_to) - first_day_timestamp;

        auto lb = lower_bound(begin(earnings_),end(earnings_),tp_from);
        auto ub = upper_bound(begin(earnings_),end(earnings_),tp_to);

        double income{};
        for (int i = tp_from; i <= tp_to; ++i) {
            income += earnings_[i];
        }
        return income;

    }

private:
    int ParseDateToTimestamp(const std::string & date) const {
        std::tm tm_1 = {};
        strptime(date.c_str(), "%Y-%m-%d", &tm_1);
        auto tp_1 = std::chrono::system_clock::from_time_t(std::mktime(&tm_1));
        int timestamp = time_point_cast<days>(tp_1)
                .time_since_epoch()
                .count();
        return timestamp;
    }

private:
    std::vector<double> earnings_;
};



int main(){




    const int number_of_years{100};
    const int start_year{2000};
    const int days_in_year{365};
    std::vector<int> years(number_of_years);
    std::vector<int> leap_years;
    std::iota(begin(years),end(years),start_year);
    std::copy_if(begin(years), end(years),back_inserter(leap_years),Year::is_leap_year);

#if 1

    std::tm tm_1 = {};
    std::tm tm_2 = {};
    std::stringstream ss("2002-01-02");
    strptime("2099-02-19", "%Y-%m-%d", &tm_1);
    strptime("2000-01-01", "%Y-%m-%d", &tm_2);
    auto tp_1 = std::chrono::system_clock::from_time_t(std::mktime(&tm_1));
    auto tp_2 = std::chrono::system_clock::from_time_t(std::mktime(&tm_2));
    int timestamp = time_point_cast<days>(tp_2)
            .time_since_epoch()
            .count();

    BudgetManager bm;
    bm.Earn("2000-01-02","2000-01-06",20);
    std::cout << bm.ComputeIncome("2000-01-01","2000-01-06") << std::endl;
    std::cout << bm.ComputeIncome("2000-01-01","2000-01-03") << std::endl;
    bm.Earn("2000-01-03","2000-01-03",10);
    std::cout << bm.ComputeIncome("2000-01-01","2000-01-07") << std::endl;


#endif



    return 0;
}