#include "date.h"
#include <iomanip>
#include <tuple>

std::ostream& operator<<(std::ostream & os, const Date & date){
    return os <<    std::setw(4) << std::setfill('0') << date.year() << '-' <<
                    std::setw(2) << date.month() << '-' <<
                    std::setw(2) << date.day();
}


std::istream & operator>>(std::istream & is, Date & date){
    int day, month, year;
    char ch;
    is >> year >> ch >> month >> ch >> day;
    date.set_year(year);
    date.set_month(month);
    date.set_day(day);
    return is;
}

const Date & get_default_date(){

    const static Date default_date(Year(2000),MonthName::Jan,Day(1));
    return default_date;
}

bool operator<(const Date &lhs, const Date &rhs) {
    return std::make_tuple(lhs.year(),lhs.month(),lhs.day()) < std::make_tuple(rhs.year(),rhs.month(),rhs.day());
}
