#include <string>
#include <vector>
#include <list>
#include <forward_list>
#include <numeric>
#include <iterator>
#include <algorithm>
using namespace std;
template <typename ForwardIterator,typename UnaryPred>
ForwardIterator max_element_if(ForwardIterator first, ForwardIterator last, UnaryPred pred){
    auto max_element = find_if(first,last, pred);
    for (auto currElem = max_element ; currElem != last; ++currElem) {
        if (currElem != max_element && pred(*currElem) && *currElem > max_element){
            max_element = currElem;
        }
    }
    return  max_element;
}