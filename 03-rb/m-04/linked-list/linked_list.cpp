#include "../test_runner.h"
#include "LinkedList.h"
#include <vector>
using namespace std;


template <typename T>
vector<T> ToVector(const LinkedList<T>& list) {
  vector<T> result;
  for (auto node = list.GetHead(); node; node = node->next) {
    result.push_back(node->value);
  }
  return result;
}

void TestPushFront() {
  LinkedList<int> list;

  list.PushFront(1);
  ASSERT_EQUAL(list.GetHead()->value, 1);
  list.PushFront(2);
  ASSERT_EQUAL(list.GetHead()->value, 2);
  list.PushFront(3);
  ASSERT_EQUAL(list.GetHead()->value, 3);

  const vector<int> expected = {3, 2, 1};
  ASSERT_EQUAL(ToVector(list), expected);
}

void TestInsertAfter() {
  LinkedList<string> list;

  list.PushFront("a");
  auto head = list.GetHead();
  ASSERT(head);
  ASSERT_EQUAL(head->value, "a");

  list.InsertAfter(head, "b");
  const vector<string> expected1 = {"a", "b"};
  ASSERT_EQUAL(ToVector(list), expected1);

  list.InsertAfter(head, "c");
  const vector<string> expected2 = {"a", "c", "b"};
  ASSERT_EQUAL(ToVector(list), expected2);
}

void TestRemoveAfter() {
  LinkedList<int> list;
  for (int i = 1; i <= 5; ++i) {
    list.PushFront(i);
  }

  const vector<int> expected = {5, 4, 3, 2, 1};
  ASSERT_EQUAL(ToVector(list), expected);

  auto next_to_head = list.GetHead()->next;
  list.RemoveAfter(next_to_head); // удаляем 3
  list.RemoveAfter(next_to_head); // удаляем 2

  const vector<int> expected1 = {5, 4, 1};
  ASSERT_EQUAL(ToVector(list), expected1);

  while (list.GetHead()->next) {
    list.RemoveAfter(list.GetHead());
  }
  ASSERT_EQUAL(list.GetHead()->value, 5);
}

void TestPopFront() {
  LinkedList<int> list;

  for (int i = 1; i <= 5; ++i) {
    list.PushFront(i);
  }
  for (int i = 1; i <= 10; ++i) {
    list.PopFront();
  }
  ASSERT(list.GetHead() == nullptr);
}

void TestDestructor(){
    LinkedList<int> list;
    for (int i = 1; i <= 100; ++i) {
        list.PushFront(i);
    }

}

void TestLargePushFront(){
    LinkedList<string> list;
    for (int i = 0; i < 10'000; ++i) {
        list.PushFront("Hello");
    }
    for (int i = 0; i < 10'000; ++i) {
        list.PopFront();
    }

}
void TestLargeInsertAfter(){
    LinkedList<int> list;
    const int LIST_SIZE{4};
    for (int i = 0; i < LIST_SIZE; ++i) {
        list.InsertAfter(list.GetHead(), i + 1);
    }
    for (int i = 0; i < LIST_SIZE; ++i) {
        list.RemoveAfter(list.GetHead());
    }
    ASSERT_EQUAL(list.GetHead()->value,1);

}
int main() {
  TestRunner tr;
  RUN_TEST(tr, TestPushFront);
  RUN_TEST(tr, TestInsertAfter);
  RUN_TEST(tr, TestRemoveAfter);
  RUN_TEST(tr, TestPopFront);
  RUN_TEST(tr, TestDestructor);
  RUN_TEST(tr, TestLargePushFront);
  RUN_TEST(tr, TestLargeInsertAfter);
  return 0;
}
