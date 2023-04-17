#include "../test_runner.h"

#include <numeric>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Реализуйте шаблон класса Paginator

template <typename Iterator>
class Page {
  private:
    Iterator begin_, end_;
    size_t page_size_;
  public:
    Page(Iterator begin, Iterator end) : begin_(begin), end_(end), page_size_(end - begin) {}
    Iterator begin() const {return begin_;}
    Iterator end() const {return end_;}
    size_t size() const {return page_size_;}

};


template <typename Iterator>
class Paginator {
  private:
    vector<Page<Iterator>> pages_;
    

  public:
    Paginator(Iterator begin, Iterator end, size_t page_size) {
          size_t n = end - begin;
          auto it =  begin;
          while (it < end){
            auto dist = static_cast<size_t>(distance(it,end));
            auto next = std::next(it, min(page_size,dist));
            pages_.push_back({it,next});
            it = next;
          }
          
      }
    vector<Page<Iterator>> pages() const {pages_;}
    auto begin() const {return pages_.begin();}
    auto end() const {return pages_.end();}
    size_t size() const {return pages_.size();}
  
};
template <typename Container>
auto Paginate(Container & c, size_t page_size){
    Paginator<typename Container::iterator> p(c.begin(),c.end(),page_size);
    return p.pages();
}
int main(){


    vector<vector<int>> v{{1,2,3},{1,2,3}};
    vector<int> vv{1,2,3};
    Paginator<vector<vector<int>>::iterator> p(begin(v), end(v),2);

    for (auto &&page : Paginate(v,2))
    {
        for (auto &&app : Paginate(page,1))
        {
            std::cout << app << " ";
        }
        cout << "\n";
        
    }
    



}