
#ifndef __DEQUE_H__
#define __DEQUE_H__ // __DEQUE_H__
#include <vector>
#include <cstddef>
#include <algorithm>
#include <stdexcept>
#include <iostream>
template <typename T>
class Deque {
    private:
        std::vector<T> put_;
        std::vector<T> get_;

    public:
        Deque(){}
        bool Empty() const {return put_.empty() && get_.empty(); }
        size_t Size() const {return (put_.size() + get_.size());}
        T & operator[](size_t index){
            return const_cast<T&>(static_cast<const T &>(*this)[index]);
        }
        const T & operator[]  (size_t index) const {
            if (index < get_.size()){
                return get_[index];
            }
            else if (index >= get_.size()){
                return put_[index % get_.size()];
            }
        }
        T & At(size_t index) {
            return const_cast<T&>(static_cast<const T&>(*this).At(index));
        }
        const T & At(size_t index) const {
            if (index >= get_.size() && (index % get_.size()) > put_.size()){
                throw std::out_of_range("Out of range error");
            } else {
                return (*this)[index];
            }

        }



        T & Front() {
            
            return const_cast<T&>(static_cast<const T &>(*this).Front());
            
            }
        const T & Front() const {
            if (get_.empty()){
                std::copy(put_.begin(),put_.end(),get_.begin());
                put_.clear();
            }
            return get_.back();
            }
        T& Back() { return put_.front();}
        const T& Back() const {return put_.front();}
        void PushFront(const T & e) { get_.push_back(e);}
        void PushBack(const T & e) {put_.push_back(e);}

        void Print() const {
            for (auto it = get_.rbegin(); it != get_.rend(); ++it)
                std::cout << *it << " ";
            for (auto &&i : put_)
            {
                std::cout << i << " ";
            }
            std::cout << "\n";
            
        }



};
#endif // __DEQUE_H__