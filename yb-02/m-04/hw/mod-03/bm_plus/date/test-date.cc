#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <chrono>
#include <sstream>
#include <ctime>
#include <map>
#include <iomanip>
#include "../test_runner.h"
using namespace std;

namespace date {
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

using namespace date;


double operator+(const std::pair<Date,double> &lhs,
        const std::pair<Date,double>& rhs){
    return lhs.second + rhs.second;
}
double operator<(const std::pair<Date,double> &lhs,
                 const std::pair<Date,double>& rhs){
    return lhs.first < rhs.first;

}
double operator>=(const std::pair<Date,double> &lhs,
                 const std::pair<Date,double>& rhs){
    return lhs.first >= rhs.first;

}
double operator>(const std::pair<Date,double> &lhs,
                 const std::pair<Date,double>& rhs){
    return lhs.first > rhs.first;

}

int main(){


    Date d1(Year(2000),Month(1),Day(1));
    Date d2(Year(2000),Month(1),Day(2));
    Date d3(Year(2000),Month(1),Day(4));

    Date d4(Year(2000),Month(1),Day(5));
    Date d5(Year(2000),Month(1),Day(10));
    Date d6(Year(2000),Month(1),Day(6));


    vector<pair<Date,double>> v;
    v.emplace_back(d1,10);
    v.emplace_back(d5,20);
    v.emplace_back(d6,30);
    v.emplace_back(d2,10);
    v.emplace_back(d3,20);

    sort(begin(v),end(v));


    pair<Date,double> p(d3,2.0);

    auto lb = upper_bound(begin(v),end(v),p);

    cout << lb->first;


    

}