#pragma once

#include <cstdlib>
#include <algorithm>
// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
public:
  SimpleVector() : size_(0), capacity_(0), data_(nullptr) , end_(nullptr) {};
  explicit SimpleVector(size_t size) :
          size_(size),
          capacity_(size),
          data_(new T[size]),
          end_(data_ + size){}
  ~SimpleVector() { delete[] data_;};

  T& operator[](size_t index) {return data_[index];};
  const T& operator[](size_t index) const {return data_[index];}

  T* begin() {return data_;};
  T* end() {return end_;};

  const T * begin() const {return data_;}
    const T * end() const {return end_;}

    size_t Size() const {return size_;};
    size_t Capacity() const {return capacity_;};

    void Reallocate(){
        if (capacity_ == 0) capacity_ = 1;
        else capacity_ *= 2;

        T * newdata = new T[capacity_];
        std::copy(data_, end_,newdata);
        delete[] data_;
        data_ = newdata;
        end_ = data_ + size_;
    }

  void PushBack(const T& value) {
      if (size_ == capacity_) {
            Reallocate();
      }
      data_[size_] = value;
      ++size_;
      ++end_;
  };

private:
    size_t size_;
    size_t capacity_;
    T * data_;
    T * end_;
  // Добавьте поля для хранения данных вектора
};
