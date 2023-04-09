#include <iostream>
#include <vector>
#include <set>
using namespace std;

template <typename Iterator>
struct IteratorRange {
private:
    Iterator first, last;
public:
    IteratorRange(Iterator f, Iterator l) : first(f), last(l) {}
    Iterator begin() const {return first;}
    Iterator end() const{ return last;}
};

template <typename Container>
auto Head(
    Container & v,
    size_t top
){
    return IteratorRange{v.begin(), next(v.begin(), min(top,v.size()))};
}

template <typename Iterator>
IteratorRange<Iterator> MakeRange(Iterator begin, Iterator end){
    return IteratorRange<Iterator>{begin,end};
}
template <typename T>
size_t RangeSize(IteratorRange<T> range){
    return range.end() - range.begin();
}

int main(){
    vector<int> v = {1,2,3,4};
    for (auto &&i : v)
    {
        ++i;
    }
    

    for (auto & x : Head(v,2)) {
        std::cout << x << " "; 
    }
    cout << endl;
    set <int > nums = {5, 7, 12, 8, 10, 5, 6, 1};
    for (auto &&i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
    

}