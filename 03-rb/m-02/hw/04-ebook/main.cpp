#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <numeric>
#include <unordered_map>


using namespace std;


bool comp(const pair<int,int> & lhs, const pair<int,int>& rhs){
    return lhs.second < rhs.second;
}


class EbookManagerSlowV1 {

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
            auto [lb,ub]  = std::equal_range(begin(info_), end(info_),*it,comp);
            auto dst = distance(begin(info_), lb);


            return (double) (dst) / (double) (info_.size() - 1);
        } else {
            return 0;
        }


    }
    size_t size() const {return info_.size();}



private:

    vector<pair<int,int>> info_;
    bool is_sorted{false};

};


class EbookManagerSlowV2 {

public:
    void read(int user_id, int page_read){
        if (info_.count(user_id)){
            auto old_page = info_[user_id];
            page_progress_.erase(  page_progress_.find(old_page));
        }
        info_[user_id] = page_read;
        page_progress_.insert(page_read);
    }

    double cheer(int user_id){

        if (info_.count(user_id)) {
            if (info_.size() == 1) return  1;

            auto page = info_[user_id];
            auto dst = distance(begin(page_progress_),page_progress_.find(page));
            return (double) (dst) / (double) (info_.size() - 1);
        } else return 0;
    }
    size_t size() const {return info_.size();}


private:
    std::multiset<int> page_progress_;
    std::unordered_map<int,int> info_;
};
class EbookManager {
public:
    EbookManager() {
        book_pages_.resize(1010,0);
    }
    void read(int user_id, int page_read) {
        if (info_.count(user_id)){
            auto old_page = info_[user_id];
            --book_pages_[old_page];
        }
        info_[user_id] = page_read;
        ++book_pages_[page_read];

    }

    double cheer(int user_id){
        if (info_.count(user_id)){
            if (info_.size() == 1) return 1;
            auto page = info_[user_id];

            auto users_behind = std::accumulate(begin(book_pages_), begin(book_pages_) + page,0);
            return (double) (users_behind) / (double) (info_.size() - 1);


        } else return 0;
    }
    size_t size() const {return info_.size();}

private:
    std::vector<int> book_pages_;
    std::unordered_map<int,int> info_;
};
#if 0
#include "../test_runner.h"
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
void test_repeated_values(){
    EbookManager em;

    em.read(1,1);
    em.read(2,1);
    em.read(3,2);
    em.read(4,2);
    em.read(5,2);
    em.read(6,3);

    ASSERT_EQUAL(em.cheer(1),0);
    ASSERT_EQUAL(em.cheer(2),0);
    ASSERT_EQUAL(em.cheer(3), (double) 2 / (em.size() - 1) );
    ASSERT_EQUAL(em.cheer(4), (double) 2 / (em.size() - 1) );
    ASSERT_EQUAL(em.cheer(5), (double) 2 / (em.size() - 1) );
    ASSERT_EQUAL(em.cheer(6), (double) 5 / (em.size() - 1) );

}
#endif
void test(){
#if 0
    TestRunner tr;
    RUN_TEST(tr,test_1);
    RUN_TEST(tr,test_repeated_values);
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

