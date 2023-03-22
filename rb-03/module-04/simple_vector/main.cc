#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
// #include "test_runner.h"

using namespace std;


template <typename T>
class SimpleVector {
    public:
    SimpleVector(size_t size) : size_(size),
                                data_(new T[size]),
                                end_(data_ + size) {}


    SimpleVector(std::initializer_list<T> lst) :  SimpleVector(lst.size()) {
        
        auto beg = lst.begin();
        for (size_t i = 0; i < lst.size(); i++)
        {
            data_[i] = *beg++;
        }
        
    }


    T& operator[](size_t index){
        return data_[index];
    }

    ~SimpleVector(){
        delete[] data_;
    }
    const T * begin() const {return data_;}
    const T * end() const {return end_;}

    T * begin() {return data_;}
    T * end() {return end_;}

    




private:
    size_t size_;
    T * data_;
    T * end_;

};




template <typename T>
void Print(const SimpleVector<T>  & v){
    for (auto &&i : v)
    {
        cout << i << " ";
    }
    cout << "\n";
    
}




int main(){
    SimpleVector<int> simple_vec{1,3,4};
    Print(simple_vec);
    Print(simple_vec);

}