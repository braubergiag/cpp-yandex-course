#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;


bool comp(const pair<int,int> & lhs, const pair<int,int>& rhs){
    return lhs.second < rhs.second;
}


class EbookManager {

public:

    void read(int user, int page){
         auto it = find_if(begin(info_), end(info_),[user](const auto &p){
            return p.first == user;
        });
         if (it != end(info_)) {
             it->second = page;
         } else info_.emplace_back(user,page);
         is_sorted = false;

    }
    double cheer(int user){
        if (!is_sorted){
            sort(begin(info_), end(info_), comp);
            is_sorted = true;
        }
        auto it = find_if(begin(info_), end(info_),[user](const auto &p){
            return p.first == user;
        });
        if (it != end(info_)){
            if (info_.size() == 1) return 1;
            auto dst = distance(begin(info_), it);

            auto page = it->second;
            while (it->second == current_page && it != end(info_)) {
                ++it;
            }

            auto second_dst = it - dst;
            return (double) (dst) / (double) (info_.size() - 1);
        } else {
            return 0;
        }


    }



private:

    vector<pair<int,int>> info_;
    bool is_sorted{false};

};


#if 0
//#include "../test_runner.h"
void test_1(){

    EbookManager em;

    ASSERT_EQUAL(em.cheer(5),0);

    em.read(1,10);
    ASSERT_EQUAL(em.cheer(1),1);

    em.read(2,5);
    em.read(3,7);
    ASSERT_EQUAL(em.cheer(2),0);
    ASSERT_EQUAL(em.cheer(3),0.5);
    em.read(3,10);
    ASSERT_EQUAL(em.cheer(3),0.5);

    em.read(3,11);
    ASSERT_EQUAL(em.cheer(3),1);
    ASSERT_EQUAL(em.cheer(1),0.5);
    ASSERT_EQUAL(em.cheer(22),0);


}

#endif
void test(){
#if 0
    TestRunner tr;
    RUN_TEST(tr,test_1);
#endif
}

int main(){

    test();
#if 1
    EbookManager em;

    int q{};
    std::cin >> q;
    while (q--){
        std::string command;
        cin >> command;

        if (command == "READ"){
            int user, page_read;
            std::cin >> user >> page_read;
            em.read(user,page_read);

        } else if (command == "CHEER"){
            int user;
            std::cin >> user;
            std:: cout << em.cheer(user) << '\n';
        }

    }
#endif
}

