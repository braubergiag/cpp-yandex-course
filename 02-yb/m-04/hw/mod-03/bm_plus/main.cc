#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <chrono>
#include <map>
#include <iomanip>
#include <array>
static constexpr int first_day_timestamp = 98614; // 1700-01-01
static constexpr int last_day_timestamp = 146096; // 2100-01-01
static constexpr int cseconds_in_day = 86400;
static constexpr int cseconds_offset = 10'800;
using namespace std::chrono;
auto ParseDateToTimestamp(const std::string & date)  {
    std::tm tm_1 = {};
    strptime(date.c_str(), "%Y-%m-%d", &tm_1);
    auto tp_1 = std::chrono::system_clock::from_time_t(std::mktime(&tm_1));
//    std::cout << date << " " << std::mktime(&tm_1) << " " << ((std::mktime(&tm_1) + cseconds_offset) / cseconds_in_day)<< std::endl;
    return  ((std::mktime(&tm_1) + cseconds_offset) / cseconds_in_day) + first_day_timestamp;
}

struct Date {
    bool operator<(const Date & oth) const {
        return std::tuple(year,month,day) < std::tuple(oth.year,oth.month,oth.day);
    }
    int year,month,day;
};


class BudgetManager {
public:
    BudgetManager() {
        data_.resize(last_day_timestamp,0);
        partials_.resize(last_day_timestamp,0);
    }

    void Earn(const std::string & date, uint64_t amount){

        data_[ ParseDateToTimestamp(date)] += amount;
    }

    uint64_t ComputeIncome(const  std::string & start_date, const  std::string & end_date) {
        if (!sums_computed_) ComputePartialSums();
        auto startIndex = ParseDateToTimestamp(start_date);
        auto endIndex = ParseDateToTimestamp(end_date);
//        if (endIndex == startIndex) return  partials_[endIndex];
        if (startIndex > 0){
            return partials_[endIndex] - partials_[startIndex - 1];
        } else if (startIndex == 0 || endIndex == 0){
            return partials_[endIndex];
        }
        return partials_[endIndex] - partials_[startIndex];

    }




private:
    void ComputePartialSums() {
        std::partial_sum(begin(data_),end(data_),begin(partials_));
        sums_computed_ = true;
    }

    std::vector<uint64_t> data_;
    std::vector<uint64_t> partials_;
    bool sums_computed_{false};

};


#if 1
#include "test_runner.h"

void test_1(){
    BudgetManager bm;
    bm.Earn("1970-01-02",20);
    bm.Earn("1970-01-03",10);
    bm.Earn("1970-01-06",10);
    bm.Earn("1970-01-07",10);
    bm.Earn("1970-01-10",10);
    ASSERT_EQUAL(bm.ComputeIncome("1970-01-10","1970-01-10"),10);
    ASSERT_EQUAL(bm.ComputeIncome("1970-01-01","1970-01-02"),20);
    ASSERT_EQUAL(bm.ComputeIncome("1970-01-01","1970-01-03"),30);
    ASSERT_EQUAL(bm.ComputeIncome("1970-01-02","1970-01-06"),40);
    ASSERT_EQUAL(bm.ComputeIncome("1970-01-03","1970-01-06"),20);
    ASSERT_EQUAL(bm.ComputeIncome("1970-01-03","1970-01-07"),30);
    ASSERT_EQUAL(bm.ComputeIncome("1970-01-01","1970-01-07"),50);
    ASSERT_EQUAL(bm.ComputeIncome("1970-01-01","1970-01-12"),60);
    ASSERT_EQUAL(bm.ComputeIncome("1970-01-01","1970-01-10"),60);
    ASSERT_EQUAL(bm.ComputeIncome("1970-01-11","1970-01-11"),0);
    ASSERT_EQUAL(bm.ComputeIncome("1970-01-09","1970-01-12"),10);



    ASSERT_EQUAL(bm.ComputeIncome("1970-01-12","1970-01-24"),0);
    ASSERT_EQUAL(bm.ComputeIncome("1970-01-01","1970-01-01"),0);


}
void test_2(){
    BudgetManager bm;
    bm.Earn("1970-01-01",20);
    ASSERT_EQUAL(bm.ComputeIncome("1970-01-01","1970-01-01"),20);


}
void test_3(){
    BudgetManager bm;
    bm.Earn("2000-01-02",20);
    bm.Earn("2000-01-06",10);
    bm.Earn("2000-01-03",10);

    ASSERT_EQUAL(bm.ComputeIncome("2000-01-01","2000-01-02"),20);
    ASSERT_EQUAL(  bm.ComputeIncome("2000-01-02","2000-01-06"),40);

}
void test_4(){
    BudgetManager bm;
    bm.Earn("1700-01-01",20);
    bm.Earn("1700-01-02",20);
    bm.Earn("1700-01-03",20);
    ASSERT_EQUAL(bm.ComputeIncome("1700-01-01","1700-01-01"),20);
    ASSERT_EQUAL(bm.ComputeIncome("1700-01-02","1700-01-02"),20);
    ASSERT_EQUAL(bm.ComputeIncome("1700-01-03","1700-01-03"),20);

    ASSERT_EQUAL(bm.ComputeIncome("1700-01-01","1700-01-02"),40);
    ASSERT_EQUAL(bm.ComputeIncome("1700-01-02","1700-01-03"),40);

    ASSERT_EQUAL(bm.ComputeIncome("1700-01-01","1700-01-03"),60);


}

void test_5(){
    BudgetManager bm;
    bm.Earn("1700-01-02",20);
    bm.Earn("1700-01-03",20);
    ASSERT_EQUAL(bm.ComputeIncome("1700-01-01","1700-01-01"),0);
    ASSERT_EQUAL(bm.ComputeIncome("1700-01-01","1700-01-02"),20);
}
void test_6(){
    BudgetManager bm;
    bm.Earn("1700-01-01",4'000'000'000);
    bm.Earn("1700-01-02",4'000'000'000);
    bm.Earn("2099-12-31",4'000'000'000);
    ASSERT_EQUAL(bm.ComputeIncome("1700-01-01","1700-01-01"),4'000'000'000);
    ASSERT_EQUAL(bm.ComputeIncome("1700-01-01","1700-01-03"),8'000'000'000);
    ASSERT_EQUAL(bm.ComputeIncome("1700-01-04","1700-01-08"),0);
    ASSERT_EQUAL(bm.ComputeIncome("1700-01-01","2099-12-31"),12'000'000'000);
}
#endif
int main(){

#if 1
    TestRunner tr;
    RUN_TEST(tr,test_1);
    RUN_TEST(tr,test_2);
    RUN_TEST(tr,test_3);
    RUN_TEST(tr,test_4);
    RUN_TEST(tr,test_5);
    RUN_TEST(tr,test_6);
#endif


#if 0
    BudgetManager bm;


    int e{0};
    std::cin >> e;
    std::string date;
    int value{0};

    while (e--) {
        std::cin >> date >> value;
        bm.Earn(date,value);

    }
    int q{0};
    std::cin >> q;
    std::string date_from, date_to;
    std::cout.precision(25);
    while (q--) {
        std::cin >> date_from >> date_to;
        std::cout << bm.ComputeIncome(date_from,date_to) << "\n";
    }


#endif



    return 0;
}