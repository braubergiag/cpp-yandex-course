#include <chrono>
#include <iostream>


#define UNIQUE_ID_IMPL(lineno)  a_local_var_ ##lineno 
#define UNIQUE_ID(lineno) UNIQUE_ID_IMPL(lineno)

#define LOG_DURATION(message) \
    LogDuration UNIQUE_ID(__LINE__){message};


class LogDuration {
public:
    explicit LogDuration(const std::string & message) :  start_(std::chrono::steady_clock::now()),message_(message + ": ") {


    }
    ~LogDuration(){
        auto finish = std::chrono::steady_clock::now();
        auto dur = finish - start_;
        std::cerr << message_  << std::chrono::duration_cast<std::chrono::milliseconds>(dur).count() << " ms" <<  std::endl;
    }
private:
    
    std::chrono::steady_clock::time_point start_;
    std::string message_;

};