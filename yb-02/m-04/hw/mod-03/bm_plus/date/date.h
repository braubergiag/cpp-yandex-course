#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>
#include <array>
#include <tuple>
#include <iomanip>

class Year {
public:
    static constexpr  int min_year{2000}, max_year{2099};
    static constexpr int days_in_year{365}, days_in_leap_year{366};
    static  int get_days_in_year(int year) {
        return is_leap_year(year) ? days_in_leap_year : days_in_year;
    };
    static  bool is_leap_year(int year){
        return year % 400 == 0 || year % 4 == 0;
    }
    explicit Year(int year = 2000) : year_(year) {};
    int year() const {return year_;}


private:
    int year_;

};

enum class MonthName {Jan = 1,Fab,March,April,May,June,July,Aug,Sept,Oct,Nov,Dec};


class Month {
    static constexpr int min_month{1}, max_month{12};
    static constexpr const std::array<int,max_month> days_in_each_month{31,28,31,30,31,30,31,31,30,31,30,31};

    class InvalidMonth : public std::invalid_argument {

    };
    public:
        explicit Month(int month = 1) : month_(month) {}
        Month(MonthName month_name) : month_(static_cast<int>(month_name)) {}
        int month() const {return month_;}
    private:
        int month_;
};
class Day {
    static constexpr int min_day{1}, max_day{31};
    class InvalidDay : public std::invalid_argument {

    };
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

    const static Date default_date(Year(2000),MonthName::Jan,Day(1));
    return default_date;
}
inline bool operator<(const Date &lhs, const Date &rhs) {
    return std::make_tuple(lhs.year(),lhs.month(),lhs.day()) < std::make_tuple(rhs.year(),rhs.month(),rhs.day());
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
