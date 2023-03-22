#include "test_runner.h"
#include "table.h"
using namespace std;





// Реализуйте здесь шаблонный класс Table
#if 1
void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
}

#endif

int main() {
  #if 1
  TestRunner tr;
  RUN_TEST(tr, TestTable);
  #endif

  return 0;
}