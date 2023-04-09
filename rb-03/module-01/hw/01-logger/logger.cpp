 // #include "../test_runner.h"
#include <sstream>
#include <string>
using namespace std;

class Logger {
public:
  explicit Logger(ostream& output_stream) : os(output_stream) {
  }

  void SetLogLine(bool value) { log_line = value; }
  void SetLogFile(bool value) { log_file= value; }

  bool LogLine() const {return log_line;}
  bool LogFile() const {return log_file;}

  void SetLine(int line) {
      line_ = line;
  }
  void SetFile(std::string file){
    file_ = file;
  }



  void Log(const string& message) {
    if (log_line && log_file) 
      os << file_ << ":" << line_ << " " << message;
    else if (log_file)
      os << file_ << " " << message;
    else if (log_line)
      os << "Line " << line_ << " " << message;
    else 
      os << message;

    os << "\n";
  }

private:
  ostream& os;
  int line_;
  std::string file_;
  bool log_line = false;
  bool log_file = false;
};

#define LOG(logger, message) {  \
    logger.SetLine(__LINE__);   \
    logger.SetFile(__FILE__);   \
    logger.Log(message);        \
}
#if 0
void TestLog() {
/* Для написания юнит-тестов в этой задаче нам нужно фиксировать конкретные
 * номера строк в ожидаемом значении (см. переменную expected ниже). Если
 * мы добавляем какой-то код выше функции TestLog, то эти номера строк меняются,
 * и наш тест начинает падать. Это неудобно.
 *
 * Чтобы этого избежать, мы используем специальный макрос #line
 * (http://en.cppreference.com/w/cpp/preprocessor/line), который позволяет
 * переопределить номер строки, а также имя файла. Благодаря ему, номера
 * строк внутри функции TestLog будут фиксированы независимо от того, какой
 * код мы добавляем перед ней*/

  ostringstream logs;
  Logger l(logs);
  LOG(l, "hello");

  l.SetLogFile(true);
  LOG(l, "hello");

  l.SetLogLine(true);
  LOG(l, "hello");

  l.SetLogFile(false);
  LOG(l, "hello");

  string expected = "hello\n";
  expected += "logger.cpp hello\n";
  expected += "logger.cpp:73 hello\n";
  expected += "Line 76 hello\n";
  ASSERT_EQUAL(logs.str(), expected);
}


int main() {

  TestRunner tr;
  RUN_TEST(tr, TestLog);
}
#endif 