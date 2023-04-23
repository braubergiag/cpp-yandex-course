#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>


template <typename It>
void PrintRange(It range_begin, It range_end){
    for (auto it = range_begin; it != range_end; ++it){
        std::cout << *it << " ";
    }
    std::cout << "\n";

}


bool isEven(int a) {
    return a % 2 == 0;
}

int main() {
    using namespace std;

    // {
    //         std::vector<int> a {1,2,23,4,4};
    //     std::vector<std::string> s {"Python", "C++", "C", "Java", "C#"};
    //     auto border = find(s.begin(), s.end(), "C");

    //     PrintRange (s.begin(), border);
    //     PrintRange(border, s.end());
    // }

    // remove_copy_if example
    {
         std::cout << "remove_copy_if example !isEven\n";
        std::vector<int> src {1,2,3,4,5,5,5,7,8} , dst;

        std::remove_copy_if(begin(src), end(src), std::back_inserter(dst),[](int a){return !isEven(a);});
        PrintRange(begin(dst), end(dst));


    }


    // remove_copy_if example
    {
         std::cout << "remove_copy_if example isEven\n";
        std::vector<int> src {1,2,3,4,5,5,5,7,8} , dst;

        std::remove_copy_if(begin(src), end(src), std::back_inserter(dst),isEven);
        PrintRange(begin(dst), end(dst));


    }



    //  // remove_copy_if example
    // {
    //      std::cout << "remove_copy_if example isEven\n";
    //      std::vector<int> src {1,2,3,4,5,5,5,7,8} , dst;

    //     std::remove_copy_if(begin(src), end(src), std::back_inserter(dst),[](int a) {return isEven(a);});
    //     PrintRange(begin(dst), end(dst));
    // }
    // {
    //     std::cout << "copy_if example isEven\n";
    //     std::vector<int> src {1,2,3,4,5,5,5,7,8} , dst;
    //     std::copy_if(begin(src), end(src), std::back_inserter(dst),[](int a) {return isEven(a);});
    //     PrintRange(begin(dst), end(dst));
    // }

    // {
    //     std::cout << "copy_if example !isEven\n";
    //     std::vector<int> src {1,2,3,4,5,5,5,7,8} , dst;
    //     std::copy_if(begin(src), end(src), std::back_inserter(dst),[](int a) {return !isEven(a);});
    //     PrintRange(begin(dst), end(dst));
    // }


    // {
    //     std::set<int> s = {1,2,3,4,5,6,7,8 };
    //     std::vector<int> v;

    //     v.assign(begin(s), end(s));
    //     auto it = std::partition(begin(v), end(v), isEven);
    //     v.erase(begin(v), it);   

    //     PrintRange(begin(v), end(v));

    // }
    // {
    //     std::set<int> s = {1,2,3,4,5,6,7,8 };
    //     std::vector<int> v;
    //     v.assign(begin(s), end(s));
    //     auto it = std::partition(begin(v), end(v), isEven);
    //     v.erase(begin(v), it);
    //     PrintRange(begin(v), end(v));


    // }
    // {           
    //     std::set<int> s = {1,2,3,4,5,6,7,8 };
    //     std::vector<int> v;
    //     vector<int> garbage;
    //     partition_copy(
    //     begin(s), end(s),
    //     back_inserter(garbage), back_inserter(v), isEven);
    //       PrintRange(begin(v), end(v));

    // }
    // {
    //     std::set<int> s = {1,2,3,4,5,6,7,8 };
    //     std::vector<int> v;
    //     v.assign(begin(s), end(s));
    //     auto it = remove_if(begin(v), end(v),
    //                         [](int x) { return !isEven(x); });
    //     v.erase(it, end(v));
    //     PrintRange(begin(v), end(v));

    // }
    // {
    //     std::set<int> s = {1,2,3,4,5,6,7,8 };
    //     std::vector<int> v;
    //     vector<int> garbage;
    //     partition_copy(
    //     begin(s), end(s),
    //     back_inserter(v), back_inserter(garbage), isEven);
    //     PrintRange(begin(v), end(v));
    // }
    // {
    //     std::set<int> s = {1,2,3,4,5,6,7,8 };
    //     std::vector<int> v;
    //     vector<int> garbage;
    //     v.assign(begin(s), end(s));
    //     auto it = remove_if(begin(v), end(v), isEven);
    //     v.erase(it, end(v));
    //      PrintRange(begin(v), end(v));

    // }
    // {
    //     std::set<int> s = {1,2,3,4,5,6,7,8 };
    //     std::vector<int> v;
    //     vector<int> garbage;
    //     v.assign(begin(s), end(s));
    //     sort(begin(v), end(v),
    //         [](int lhs, int rhs) { return isEven(lhs) > isEven(rhs); });
    //     auto it = partition_point(begin(v), end(v), isEven);
    //     v.erase(begin(v), it);
    //       PrintRange(begin(v), end(v));

    // }

    // {
    //     std::set<int> s = {1,2,3,4,5,6,7,8 };
    //     std::vector<int> v;
    //     vector<int> garbage;
    //     v.assign(begin(s), end(s));
    //     sort(begin(v), end(v),
    //         [](int lhs, int rhs) { return isEven(lhs) > isEven(rhs); });
    //     auto it = partition_point(begin(v), end(v), isEven);
    //     v.erase(it, end(v));
    //      PrintRange(begin(v), end(v));

    // }
    #if 0
    {
        vector<int> v {1,2,3,4,5};
        PrintRange(rbegin(v), rend(v));

        vector<string> langs = {"C++","C#", "Java","Python", "C"};
        auto it = find_if(rbegin(langs), rend(langs), [](const string & lang) {return lang[0] == 'C';});

        cout << *it << endl;
    }
    {
        vector<string> langs = {"C++","C#", "Java","Python", "C"};
        auto it = partition(begin(langs), end(langs),[](const string& lang){return lang[0] == 'C';});
        PrintRange(begin(langs), it);
    }

    {
        vector<string> langs = {"C++","C#", "Java","Python", "C"};
        vector<string> c_langs;
        copy_if(begin(langs), end(langs),back_inserter(c_langs),[](const string& lang){return lang[0] == 'C';});
        PrintRange(begin(c_langs), end(c_langs));
    }
    #endif

    {
                vector<int> vec = {1,2,3};
                auto vector_begin = begin(vec);
                auto vector_end = end(vec);

                string str = {"Hi","Hello"};
                auto string_begin = begin(str);
                auto string_end = end(str);

                set<int> s = {1,2,3};
                auto set_begin = begin(s);
                auto set_end = end(s);

                std::partial_sum(vector_begin,vector_end,set_begin);
                // next_permutation(set_begin,set_end);
                // auto res = is_permutation(set_begin,set_end,back_inserter(vec));
                // auto res = is_heap(set_begin,set_end);


    }


}