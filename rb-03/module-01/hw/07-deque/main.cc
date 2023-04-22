#include "../test_runner.h"
#include <string>
#include <deque>
#include "my_deque.h"

using namespace std;

void test_front_back_At_operator(){
    Deque<int> deq;

    deq.PushFront(1);
    deq.PushFront(2);
    deq.PushFront(3);

    deq.PushBack(4);
    deq.PushBack(5);
    deq.PushBack(6);

    ASSERT_EQUAL(deq.At(0),3);
    ASSERT_EQUAL(deq.At(1),2);
    ASSERT_EQUAL(deq.At(2),1);

    
    ASSERT_EQUAL(deq.At(3),4);
    ASSERT_EQUAL(deq.At(4),5);
    ASSERT_EQUAL(deq.At(5),6);


}
void test_front_back_square_operator(){
    Deque<int> deq;

    const size_t COUNT_1{3},COUNT_2{6};
    for (size_t i = 0; i < COUNT_1; i++)
        deq.PushFront(i);
    for (size_t i = 0; i < COUNT_2; i++)
        deq.PushBack(i);

    for (size_t i = 0; i < COUNT_1; i++)
        ASSERT_EQUAL(deq[i],COUNT_1 - i - 1);
    for (size_t i = COUNT_1; i < COUNT_2; i++)
        ASSERT_EQUAL(deq[COUNT_1 + i], i);

}
void test_front_empty(){
    Deque<int> deq;
    const size_t COUNT{3};
    for (size_t i = 0; i < COUNT; i++) 
        deq.PushBack(i);
    for (size_t i = 0; i < COUNT; i++){
        ASSERT_EQUAL(deq.At(i),i);
        ASSERT_EQUAL(deq[i],i);
    }
    ASSERT_EQUAL(deq.Size(),COUNT);
}

void test_back_empty(){
    Deque<int> deq;
    const size_t COUNT{3};
    for (size_t i = 0; i < COUNT; i++)
        deq.PushFront(i);
    for (size_t i = 0; i < COUNT; i++)
    {
        ASSERT_EQUAL(deq.At(i),COUNT - i - 1);
        ASSERT_EQUAL(deq[i],COUNT - i - 1);
    }
    ASSERT_EQUAL(deq.Size(),COUNT);
}

void test_wrong_index(){
    Deque<int> deq;
}


int main() {

    TestRunner runner;
    RUN_TEST(runner,test_front_back_At_operator);
    RUN_TEST(runner,test_front_empty);
    RUN_TEST(runner,test_back_empty);
    RUN_TEST(runner,test_front_back_square_operator);



    

    return 0;
}