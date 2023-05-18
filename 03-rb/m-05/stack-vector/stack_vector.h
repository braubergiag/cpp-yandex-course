#pragma once

#include <stdexcept>
using namespace std;

template <typename T, size_t N>
class StackVector {
public:
    using iterator = T * ;
    using const_iterator = const T * ;


  explicit StackVector(size_t a_size = 0) : size_(a_size) {
      if (a_size > N) throw std::invalid_argument("");
  }

    T& operator[](size_t index) {return  data_[index];}
    const T& operator[](size_t index) const {return  data_[index];};

    iterator begin() {return  data_;};
    iterator  end() { return  data_ + size_;};
    const_iterator begin() const { return data_;};
    const_iterator end() const {return  data_ + size_;};

    size_t Size() const {return size_;};
    size_t Capacity() const {return N;};

  void PushBack(const T& value) {
      if (size_ == N) throw std::overflow_error("");
      data_[size_] = value;
      ++size_;
  };
  T PopBack() {
      if (size_ == 0){
          throw std::underflow_error("");
      }
      return data_[--size_];
  }

private:
    size_t size_;
    T data_[N];
};

