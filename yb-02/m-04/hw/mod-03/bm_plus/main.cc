#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <chrono>
#include <map>
#include <iomanip>
#include <array>






namespace Date {
    class Year {
    public:
        explicit Year(int year = 2000) : year_(year) {};
        int year() const {return year_;}


    private:
        int year_;

    };

    class Month {
    public:
        explicit Month(int month = 1) : month_(month) {}
        int month() const {return month_;}
    private:
        int month_;
    };
    class Day {
    public:
        explicit Day(int day = 1) : day_(day) {}
        int day() const {return day_;}
    private:
        int day_;
    };
    class Date;
    inline const Date & get_default_date();
    inline std::istream & operator>>(std::istream & is, Date & date);

    class Date {
    public:
        Date(): year_(get_default_date().year_),
                month_(get_default_date().month_),
                day_(get_default_date().day_){}
        Date(Year year, Month month, Day day) : year_(year), month_(month), day_(day) {};
        Date(const std::string & s) {
            std::stringstream ss(s);
            ss >> (*this);


        }
    public:
        int year() const {return year_.year();}
        int month() const {return month_.month();}
        int day() const {return day_.day();}

        void set_day(int dd) { day_ = Day(dd);}
        void set_month(int mm) {month_ = Month(mm);}
        void set_year(int yy) {year_ = Year(yy);}
    private:
        Year year_;
        Month month_;
        Day day_;
    };

    inline const Date & get_default_date(){

        const static Date default_date(Year(2000),Month(1),Day(1));
        return default_date;
    }
    inline bool operator<(const Date &lhs, const Date &rhs) {
        return std::make_tuple(lhs.year(),lhs.month(),lhs.day()) < std::make_tuple(rhs.year(),rhs.month(),rhs.day());
    }
    inline bool operator>(const Date &lhs, const Date &rhs) {
        return std::make_tuple(lhs.year(),lhs.month(),lhs.day()) > std::make_tuple(rhs.year(),rhs.month(),rhs.day());
    }
    inline bool operator>=(const Date &lhs, const Date &rhs) {
        return std::make_tuple(lhs.year(),lhs.month(),lhs.day()) >= std::make_tuple(rhs.year(),rhs.month(),rhs.day());
    }

    inline bool operator<=(const Date &lhs, const Date &rhs) {
        return std::make_tuple(lhs.year(),lhs.month(),lhs.day()) <= std::make_tuple(rhs.year(),rhs.month(),rhs.day());

    }
    inline std::ostream& operator<<(std::ostream & os, const Date & date){
        return os << std::setw(4) << std::setfill('0') << date.year() << '-' <<
                  std::setw(2) << date.month() << '-' <<
                  std::setw(2) << date.day();
    }


    inline std::istream & operator>>(std::istream & is, Date & date){
        int day, month, year;
        char ch;
        is >> year >> ch >> month >> ch >> day;
        date.set_year(year);
        date.set_month(month);
        date.set_day(day);
        return is;
    }

}



double operator+(const std::pair<Date::Date,double> &lhs,
        const std::pair<Date::Date,double>& rhs){
    return lhs.second + rhs.second;
}
double operator<(const std::pair<Date::Date,double> &lhs,
                 const std::pair<Date::Date,double>& rhs){
    return lhs.first < rhs.first;

}
double operator>=(const std::pair<Date::Date,double> &lhs,
                 const std::pair<Date::Date,double>& rhs){
    return lhs.first >= rhs.first;

}
double operator>(const std::pair<Date::Date,double> &lhs,
                 const std::pair<Date::Date,double>& rhs){
    return lhs.first > rhs.first;

}
class BudgetManager {
private:
public:
        BudgetManager()  {}


    void Earn(const Date::Date & date, int earning) {
        earnings_db_.emplace_back(date,earning);

    }
    void Earn(const std::string & date_str, int earning) {
        auto date = Date::Date(date_str);
        earnings_db_.emplace_back(date,earning);
    }



    double ComputeIncome(const std::string & date_from,const std::string & date_to) {

        if (!init_partial_sums_) ComputePartialSums();

        auto tp_from = Date::Date(date_from);
        auto tp_to = Date::Date(date_to);

        auto temp{tp_from};
        tp_from = std::min(tp_from,tp_to);
        tp_to = std::max(temp,tp_to);

        auto lb = std::lower_bound(begin(earnings_db_),end(earnings_db_),
                                      std::make_pair(tp_from,0.0));
        auto ub = std::upper_bound(begin(earnings_db_),end(earnings_db_),
                                     std::make_pair(tp_to,0.0));

        auto start = std::distance(begin(earnings_db_),lb);
        auto end = std::distance(begin(earnings_db_),ub);

        auto begin_earning = begin(partial_sums_) + start;
        auto end_earning = begin(partial_sums_) + end;

        return  (*end_earning - *begin_earning);

    }
private:
    void ComputePartialSums(){
        init_partial_sums_ = true;
        std::vector<double> earnings;
        std::vector<double> partial_sums;

        std::sort(begin(earnings_db_),end(earnings_db_));

        for (auto && i: earnings_db_) {
            earnings.push_back(i.second);
        }
        partial_sums_.push_back(0);
        std::partial_sum(std::begin(earnings),end(earnings), std::back_inserter(partial_sums_));
        partial_sums_.push_back(partial_sums_.back());
}
private:
    std::vector<std::pair<Date::Date,double>> earnings_db_;
    std::vector<double> partial_sums_;
    bool init_partial_sums_{false};
};

#if 1
#include "test_runner.h"

void test_1(){
    BudgetManager bm;
    bm.Earn("2000-01-02",20);
    bm.Earn("2000-01-03",10);
    bm.Earn("2000-01-06",10);
    bm.Earn("2000-01-07",10);
    bm.Earn("2000-01-10",10);
    ASSERT_EQUAL(bm.ComputeIncome("2000-01-01","2000-01-02"),20);
    ASSERT_EQUAL(bm.ComputeIncome("2000-01-01","2000-01-03"),30);
    ASSERT_EQUAL(bm.ComputeIncome("2000-01-02","2000-01-06"),40);
    ASSERT_EQUAL(bm.ComputeIncome("2000-01-03","2000-01-06"),20);
    ASSERT_EQUAL(bm.ComputeIncome("2000-01-03","2000-01-07"),30);
    ASSERT_EQUAL(bm.ComputeIncome("2000-01-01","2000-01-07"),50);
    ASSERT_EQUAL(bm.ComputeIncome("2000-01-01","2000-01-12"),60);
    ASSERT_EQUAL(bm.ComputeIncome("2000-01-10","2000-01-10"),10);
    ASSERT_EQUAL(bm.ComputeIncome("2000-01-12","2000-01-24"),0);
    ASSERT_EQUAL(bm.ComputeIncome("2000-01-01","2000-01-01"),0);
    ASSERT_EQUAL(bm.ComputeIncome("1999-01-01","2000-01-01"),0);


}
void test_2(){
    BudgetManager bm;
    bm.Earn("2000-01-02",20);
    bm.Earn("2000-01-06",10);
    bm.Earn("2000-01-03",10);
    ASSERT_EQUAL(bm.ComputeIncome("2000-01-01","2000-01-02"),20);
    ASSERT_EQUAL(bm.ComputeIncome("2000-01-02","2000-01-06"),40);


}
#endif
int main(){

#if 1
    TestRunner tr;
    RUN_TEST(tr,test_1);
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