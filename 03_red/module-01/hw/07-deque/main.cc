#include "test_runner.h"
#include <string>
#include <deque>
#include "my_deque.h"



void test_push_back(){
    Deque<int> deq;
    std::deque<int> deqstd;
    deq.PushBack(21);
    deqstd.push_back(21);
    ASSERT_EQUAL(deq.Back(),deqstd.back());

    deq.PushFront(42);
    deqstd.push_front(42);
    ASSERT_EQUAL(deq.Front(), deqstd.front());
    ASSERT_EQUAL(deq.Size(), deqstd.size());
    
}

void test_push_front(){
    Deque<int> deq;
    std::deque<int> deqstd;
    deq.PushFront(20);
    deqstd.push_front(20);
    ASSERT_EQUAL(deq.Front(), deqstd.front());
}

void test_empty(){
    Deque<int> deq;
    ASSERT(deq.Empty());

    deq.PushBack(21);
    ASSERT(!deq.Empty());
}

void test_operator(){
    Deque<int> deq;
    std::deque<int> deqstd;
    deq.PushFront(1);
    deq.PushFront(2);
    deq.PushFront(3);

    deqstd.push_front(1);
    deqstd.push_front(2);
    deqstd.push_front(3);


    ASSERT_EQUAL(deq[0], deqstd[0]);
    ASSERT_EQUAL(deq[1], deqstd[1]);
    ASSERT_EQUAL(deq[2], deqstd[2]);


    deq.PushBack(10);
    deq.PushBack(11);

    deqstd.push_back(10);
    deqstd.push_back(11);

    ASSERT_EQUAL(deq[3],deqstd[3]);
    ASSERT_EQUAL(deq[4],deqstd[4]);
}

void test_at(){
    Deque<int> deq;
    deq.PushFront(1);
    deq.PushFront(2);
    deq.PushFront(3);

    ASSERT_EQUAL(deq.At(0), 3);
    ASSERT_EQUAL(deq.At(1), 2);
    ASSERT_EQUAL(deq.At(2), 1);


    deq.PushBack(10);
    deq.PushBack(11);

    ASSERT_EQUAL(deq.At(3),10);
    ASSERT_EQUAL(deq.At(4),11);
}

void test_at_exception(){
    Deque<int> deq;
    deq.PushFront(2);
    try {
        deq.At(1);
    } catch (const std::out_of_range & e){

    }

}

void test_size(){
    Deque<int> deq;
    deq.PushBack(23);
    deq.PushFront(32);
    ASSERT_EQUAL(deq.Size(), 2);
}

void test_back(){
    Deque<std::string> deq;
    auto s{"Hello"};
    deq.PushBack(s);
    ASSERT_EQUAL(deq.Front(), s);
}
void test_front(){
    Deque<std::string> deq;
    auto s{"Hi"};
    deq.PushFront(s);
    ASSERT_EQUAL(deq.Back(),s);
}


int main() {

    TestRunner runner;
    RUN_TEST(runner,test_push_back);
    RUN_TEST(runner,test_push_front);
    RUN_TEST(runner,test_empty);
    RUN_TEST(runner,test_size);
    RUN_TEST(runner,test_operator);
    RUN_TEST(runner,test_at);
    RUN_TEST(runner,test_at_exception);
    RUN_TEST(runner,test_back);
    RUN_TEST(runner,test_front);


    

    return 0;
}