#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <chrono>
#include <sstream>
#include <ctime>
#include <map>
//#include "test_runner.h"
using namespace std::chrono;


class BudgetManager {
private:
    static constexpr int first_day_timestamp = 10'956;
    static constexpr int cseconds_in_day = 86400;


public:
        BudgetManager()  {
            earnings_.resize(50'000);
            std::fill(begin(earnings_),end(earnings_),0.0);
        }


    void Earn(const std::string & date_from,const std::string & date_to, int earning) {
        auto tp_from = ParseDateToTimestamp(date_from);
        auto tp_to = ParseDateToTimestamp(date_to);
#if 1
        auto temp{tp_from};
        tp_from = std::min(tp_from,tp_to);
        tp_to = std::max(temp,tp_to);
#endif
        double earning_by_each_day = static_cast<double>(earning) / ((tp_to - tp_from) + 1);
        for (int timestamp = tp_from; timestamp <= tp_to; ++timestamp) {
            earnings_[timestamp] += earning_by_each_day;
        }
    }
    double ComputeIncome(const std::string & date_from,const std::string & date_to) {
        auto tp_from = ParseDateToTimestamp(date_from);
        auto tp_to = ParseDateToTimestamp(date_to);

        auto temp{tp_from};
        tp_from = std::min(tp_from,tp_to);
        tp_to = std::max(temp,tp_to);
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
        ::uint64_t timestamp = time_point_cast<seconds>(tp_1)
                .time_since_epoch()
                .count();
        timestamp /= cseconds_in_day;
        return (timestamp - first_day_timestamp);
    }

private:
    std::vector<double> earnings_;
};
#if 0
void test_1(){
    BudgetManager bm;
    bm.Earn("2000-01-01","2000-01-03",30);
    ASSERT_EQUAL(bm.ComputeIncome("2000-01-01","2000-01-01"),10);
    ASSERT_EQUAL(bm.ComputeIncome("2000-01-01","2000-01-02"),20);
    ASSERT_EQUAL(bm.ComputeIncome("2000-01-01","2000-01-03"),30);
    ASSERT_EQUAL(bm.ComputeIncome("2000-01-03","2000-01-01"),30);


}
void test_2(){
    BudgetManager bm;
    bm.Earn("2000-01-02","2000-01-06",20);
    ASSERT_EQUAL(bm.ComputeIncome("2000-01-01","2001-01-01"),20);
    ASSERT_EQUAL(bm.ComputeIncome("2000-01-01","2000-01-03"),8);
    bm.Earn("2000-01-03","2000-01-03",10);
    ASSERT_EQUAL(bm.ComputeIncome("2000-01-01","2001-01-01"),30);
}

void test_3(){
    BudgetManager bm;
    bm.Earn("2000-01-06","2000-01-02",20);
    ASSERT_EQUAL(bm.ComputeIncome("2000-01-01","2001-01-01"),20);
    ASSERT_EQUAL(bm.ComputeIncome("2000-01-01","2000-01-03"),8);
    bm.Earn("2000-01-03","2000-01-03",10);
    ASSERT_EQUAL(bm.ComputeIncome("2000-01-01","2001-01-01"),30);
}
#endif
void testing_date(){


#if 0

    std::tm tm_1 = {};
    std::tm tm_2 = {};
    std::stringstream ss("2002-01-02");
    strptime("2099-02-19", "%Y-%m-%d", &tm_1);
    strptime("2000-01-01", "%Y-%m-%d", &tm_2);
    auto tp_1 = std::chrono::system_clock::from_time_t(std::mktime(&tm_1));
    auto tp_2 = std::chrono::system_clock::from_time_t(std::mktime(&tm_2));
    ::uint64_t timestamp = time_point_cast<seconds>(tp_1)
            .time_since_epoch()
            .count();
#endif
};
int main(){

#if 0
    TestRunner tr;
    RUN_TEST(tr,test_1);
    RUN_TEST(tr,test_2);
    RUN_TEST(tr,test_3);
#endif



#if 1
    int q{0};
    std::cin >> q;
    std::string command,date_from,date_to;
    double value;

    BudgetManager bm;
    std::cout.precision(25);
    while (q--) {
        std::cin >> command;
        if (command == "Earn"){
            std::cin >> date_from >> date_to >> value;
            bm.Earn(date_from,date_to,value);
        } else if (command == "ComputeIncome"){
            std::cin >> date_from >> date_to;
            std::cout << bm.ComputeIncome(date_from,date_to) << "\n";
        }
    }


#endif



    return 0;
}