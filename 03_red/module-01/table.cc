#include "test_runner.h"

using namespace std;


template <typename T>
class Table {
    public:
    Table(size_t nrows,size_t ncols)  {}

    pair<size_t,size_t> Size() const {
        return make_pait(nrows_,ncols_);
    }

    void Resize(size_t nrows, size_t ncols) {

    }

    private:
        size_t nrows_;
        size_t ncols_;



};



// Реализуйте здесь шаблонный класс Table

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

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestTable);
  return 0;
}