#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <tuple>
#include <vector>
#include <map>
#include <utility>
#include <array>
#include <set>


#include <sstream>
#include <iomanip>



#define RUN_TEST(tr,func) \
    tr.RunTest(func,#func)


template <typename U , typename V>
void AssertEqual(const U & u, const V & v,const std::string& hint = {}){
    std::stringstream ss;
    if (u != v){
        ss  << std::setw(20) <<  "Assertion failed:\t" << u << " != " << v << std::setw(10) << "(" << hint << ")";
        throw std::runtime_error(ss.str());
    }
}

#define ASSERT_EQUAL(u,v) {                     \
    std::stringstream info;                     \
    info    << #u << " != " << #v << ","        \
            << __FILE__ << ":" << __LINE__;     \
    AssertEqual(u,v,info.str());                \
}

#define ASSERT(u) {                       \
    std::stringstream info;                     \
    info    << #u << " is false" << ","         \
            << __FILE__ << ":" << __LINE__;     \
    Assert(u,info.str());                       \
}


void Assert(bool val, const std::string & hint = {}){
    AssertEqual(val, true,hint);
}

class TestRunner {

public:
    TestRunner() = default;


    template <typename Function>
    void RunTest(Function test,const std::string& test_name = {}){
        try
        {
            test();
            std::cerr  <<   "[" << test_name << "]\t" << "OK" << "\n";
            ++passed_tests_;
        }
        catch(const std::exception& e)
        {
            std::cerr  <<   "[" << test_name << "]\t" << e.what() << "\n";
            ++failed_tests_;
        }
        
    }

    ~TestRunner(){
        PrintStatistics();
        if (failed_tests_ > 0) {
            exit(1);
        }
    }

    void PrintStatistics(){
        std::cout << "=================\n"
             << "Test passed: " << passed_tests_ << '\n'
             << "Test failed: " << failed_tests_ << '\n';
        
    }



private:
    int failed_tests_{0};
    int passed_tests_{0};


};


template <typename Collection>
std::string Printer(const Collection & collection, char sep){

    std::stringstream ss;
    bool first{true};
    for (const auto & el: collection){
        if (!first) {
            ss << sep;
        }
        first = false;
        ss << el;
    }


    return ss.str();
    
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> & v ){
   return os << "[" << Printer(v,',') << "]";
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::set<T> & s) {
    return os << "(" << Printer(s,',') << ")";
}
template <typename T, size_t size>
std::ostream& operator<<(std::ostream& os, const std::array<T,size> & a ){
    return os << "<" << Printer(a,',') << ">";
}

template <typename First, typename Second>
std::ostream& operator<<(std::ostream & os, const std::pair<First,Second> p){
    return os << "(" << p.first << "," << p.second << ")";
}


template <typename Key, typename Value>
std::ostream& operator<<(std::ostream & os, const std::map<Key,Value> & m){
    return os << "{" << Printer(m,',') << "}";

}
