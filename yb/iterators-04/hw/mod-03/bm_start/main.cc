#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <chrono>
#include "test_runner.h"
#include "date.h"


int  DateToIndex() {}

int main(){




    const int number_of_years{100};
    const int start_year{2000};
    const int days_in_year{365};
    const std::vector<int> days_in_each_month{31,28,31,30,31,30,31,31,30,31,30,31};
    std::vector<int> years(number_of_years);
    std::vector<int> leap_years;
    std::iota(begin(years),end(years),start_year);
    std::copy_if(begin(years), end(years),back_inserter(leap_years),IsLeapYear);


    std::vector<int> earnings_by_day(number_of_years * days_in_year + leap_years.size());


    Date date1(Year(2015),Month(12),Day(1));
    Date date2(Year(1992),MonthName::April,Day(1));
    Date date3(Year(992),Month(3),Day(1));

    std::cout << date2 << "\n";
    std::cout << date1 << "\n";
    std::cout << date3 << "\n";

    Date date;
    std::cout << date << '\n';
    std::cin >> date;
    std::cout << date;
    return 0;
}