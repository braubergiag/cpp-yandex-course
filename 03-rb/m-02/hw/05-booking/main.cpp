#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

using Time = ::int64_t;
static const int SECONDS_IN_DAY{86'400};

struct BookingInfo{
    BookingInfo(Time time, int rooms_count) : time_(time), rooms_count_(rooms_count) {}
    int64_t time_;
    int rooms_count_;
};

struct ClientManager {
    int current_rooms_count(Time current_time) const {
        auto rooms_count{0};
        auto diff_time = current_time - SECONDS_IN_DAY;

        auto it = rbegin(booking_info_);
        while (it->time_ > diff_time && it != rend(booking_info_)) {
            rooms_count += it->rooms_count_;
            ++it;
         }
        return rooms_count;
    }
    void add_booking(Time time, int rooms_count) {
        booking_info_.emplace_back(time,rooms_count);
        last_booking_time_ = time;
    }
    Time get_last_booking_time() const {
        return last_booking_time_;
    }
private:
    Time last_booking_time_{0};
    vector<BookingInfo> booking_info_;
    vector<Time> timestamps_;
};


class HotelManager {
public:
    void add_entry(Time time,int client_id, int room_count){
        hotel_db_[client_id].add_booking(time,room_count);
//        hotel_db_.emplace_back(client_id,BookingInfo(time,room_count));
    }
    auto clients(Time current_time) const {
        return  count_if(begin(hotel_db_),end(hotel_db_),
                         [current_time](const auto & p){
                             auto & hotel_info = p.second;
                             return hotel_info.get_last_booking_time() > current_time - SECONDS_IN_DAY;
                         });
    }
    int rooms(Time current_time) const {
        auto rooms_count{0};
        for (auto & [key,value]: hotel_db_) {
            if (value.get_last_booking_time() > current_time - SECONDS_IN_DAY){
                rooms_count += value.current_rooms_count(current_time);
            }
        }
        return rooms_count;
    }
private:
    using client_id_t = int;
    std::unordered_map<client_id_t,ClientManager> hotel_db_;
//    std::vector<pair<int,BookingInfo>> hotel_db_;
};




class BookingManager {
    using hotel_name_t = std::string;

public:

    void book(int64_t time, const hotel_name_t& hotel_name, int client_id, int room_count){
        db_[hotel_name].add_entry(time,client_id,room_count);
        last_booking_time_ = time;
    }
    size_t clients(const string& hotel_name) {
        if (db_.count(hotel_name)) {return db_[hotel_name].clients(last_booking_time_);}
        else return 0;
    }
    size_t rooms(const string& hotel_name) {
        if (db_.count(hotel_name)) {return db_[hotel_name].rooms(last_booking_time_);}
        else return 0;
    }
private:
    Time last_booking_time_{0};
    unordered_map<hotel_name_t,HotelManager> db_;

};

#if 0

#include "../test_runner.h"

void test_example(){
    BookingManager bm;
    ASSERT_EQUAL(bm.clients("Marriott"),0);
    ASSERT_EQUAL(bm.rooms("Marriott"),0);
    bm.book(10,"FourSeasons",1,2);
    bm.book(10,"Marriott",1,1);
    bm.book(86409,"FourSeasons",2,1);
    ASSERT_EQUAL(bm.clients("FourSeasons"),2);
    ASSERT_EQUAL(bm.rooms("FourSeasons"),3);
    ASSERT_EQUAL(bm.clients("Marriott"),1);
    bm.book(86410,"Marriott",2,10);
    ASSERT_EQUAL(bm.rooms("FourSeasons"),1);
    ASSERT_EQUAL(bm.rooms("Marriott"),10);

}

void test_clients_count(){
    BookingManager bm;
    bm.book(10,"FourSeasons",1,1);
    bm.book(5,"FourSeasons",2,1);
    bm.book(86400,"Marriott",1,1);
    ASSERT_EQUAL(bm.clients("FourSeasons"),2);

    bm.book(86405,"Marriott",2,1);
    ASSERT_EQUAL(bm.clients("FourSeasons"),1);
    bm.book(86410,"Marriott",2,1);
    ASSERT_EQUAL(bm.clients("FourSeasons"),0);
    ASSERT_EQUAL(bm.clients("Marriott"),2);
}

void test_rooms_count(){
    BookingManager bm;
    bm.book(10,"FourSeasons",1,1);
    bm.book(5,"FourSeasons",2,1);
    bm.book(86400,"Marriott",1,1);
    ASSERT_EQUAL(bm.rooms("FourSeasons"),2);

    bm.book(86405,"Marriott",2,1);
    ASSERT_EQUAL(bm.rooms("FourSeasons"),1);
    bm.book(86410,"Marriott",3,1);
    ASSERT_EQUAL(bm.rooms("FourSeasons"),0);

}
void test_1(){
    BookingManager bm;
    bm.book(-10,"FourSeasons",1,1);
    bm.book(-5,"FourSeasons",2,1);
    bm.book(5,"Marriott",1,1);
    ASSERT_EQUAL(bm.rooms("FourSeasons"),2);
    ASSERT_EQUAL(bm.clients("FourSeasons"),2);

    bm.book(86390,"Marriott",2,1);
    ASSERT_EQUAL(bm.rooms("FourSeasons"),1);
    ASSERT_EQUAL(bm.clients("FourSeasons"),1);
    bm.book(86400,"Marriott",3,1);
    ASSERT_EQUAL(bm.rooms("FourSeasons"),0);
    ASSERT_EQUAL(bm.clients("FourSeasons"),0);


    ASSERT_EQUAL(bm.rooms("Marriott"),3);
    ASSERT_EQUAL(bm.clients("Marriott"),3);

}

void test_bookings_from_one_client(){
    BookingManager bm;
    bm.book(0,"FourSeasons",1,1);
    bm.book(1,"FourSeasons",1,1);
    bm.book(2,"FourSeasons",1,1);


    ASSERT_EQUAL(bm.clients("FourSeasons"),1);
    ASSERT_EQUAL(bm.rooms("FourSeasons"),3);

    bm.book(10,"FourSeasons",1,3);
    bm.book(15,"FourSeasons",1,3);
    bm.book(86405,"FourSeasons",1,3);


    ASSERT_EQUAL(bm.clients("FourSeasons"),1);
    ASSERT_EQUAL(bm.rooms("FourSeasons"),9);


}
#endif
void run_tests(){
#if 0
    TestRunner tr;
    RUN_TEST(tr,test_example);
    RUN_TEST(tr,test_clients_count);
    RUN_TEST(tr,test_rooms_count);
    RUN_TEST(tr,test_1);
    RUN_TEST(tr,test_bookings_from_one_client);
#endif

}

int main(){

    run_tests();

#if 1
    int q{};
    std::cin >> q;
    BookingManager bm;
    string command;
    while (q--){
        std::cin >> command;
        if (command == "BOOK"){
            string hotel_name;
            int64_t time{0};
            int client_id{0}, rooms_count{0};
            cin >> time >> hotel_name >> client_id >> rooms_count;
            bm.book(time,hotel_name,client_id,rooms_count);
        } else if (command == "ROOMS"){
            string hotel_name;
            cin >> hotel_name;
            cout << bm.rooms(hotel_name) << "\n";
        } else if (command == "CLIENTS"){
            string hotel_name;
            cin >> hotel_name;
            cout << bm.clients(hotel_name) << "\n";
        }

    }
#endif

}
