
#include <numeric>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Реализуйте шаблон класса Paginator

template <typename Iterator>
class IteratorRange {
  private:
    Iterator begin_, end_;
    size_t size_;
  public:
    IteratorRange(Iterator begin, Iterator end) : begin_(begin), end_(end), size_(distance(begin,end))  {}
    Iterator begin() const {return begin_;}
    Iterator end() const {return end_;}
    size_t size() const {return size_;}

};


template <typename Iterator>
class Paginator {
  private:
    vector<IteratorRange<Iterator>> pages_;
    

  public:
    Paginator(Iterator begin, Iterator end, size_t page_size) {
          auto it =  begin;
          while (it < end){
            auto dist = static_cast<size_t>(distance(it,end));
            auto next = std::next(it, min(page_size,dist));
            pages_.push_back({it,next});
            it = next;
          }

          for (auto left = distance(begin,end); left > 0;) {
              auto current_page_size = min(page_size, left);
              Iterator current_page_end = next(begin, current_page_size);
              pages_.push_back({begin,current_page_end});

              left -= current_page_size;
              begin = current_page_end;

          }
          
      }
    auto begin() const {return pages_.begin();}
    auto end() const {return pages_.end();}
    size_t size() const {return pages_.size();}
  
};


template <typename C>
auto Paginate(C& c, size_t page_size) {
  return Paginator(c.begin(),c.end(), page_size);

}
int main(){



    



}