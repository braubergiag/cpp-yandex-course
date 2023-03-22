#pragma once

#include <vector>
#include <cstddef>
#include <stdexcept>
template <typename T>
class Deque {
    private:
        std::vector<T> back_;
        std::vector<T> front_;
    public:
        Deque(){}

        bool Empty() const {return (back_.empty() && front_.empty());}
        size_t Size() const {return back_.size() + front_.size();}


        void PushBack(const T & element) {back_.push_back(element);}
        const T & Back() const {return back_.back();};
        T & Back() {return back_.back();};

        void PushFront(const T & element) { front_.push_back(element);}
        const T & Front() const {return front_.back();}
        T & Front() {return front_.back();}


        const T & operator[](size_t index) const {
            if (index < front_.size()){
                auto pos = front_.size() - index - 1;
                return front_[pos];
            }
            else 
                return back_[index % front_.size()];
        };
        T & operator[](size_t index) {
            return const_cast<T&>(static_cast<const Deque&>(*this)[index]);
        }

        const T & At(size_t index) const {
            if (index < (front_.size() + back_.size()))
                return (*this)[index];
            else
                throw std::out_of_range("Out of range");
        };
        T & At(size_t index) {
            return const_cast<T&>(static_cast<const Deque&>(*this).At(index));
        };
};