#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct BookingInfo{
    int64_t time_;
    int rooms_count_;
};

class HotelInfo{
public:
    void add_entry(int64_t time,int client_id, int room_count){
        current_time_ = time;
        if (hotel_db_.count(client_id) && hotel_db_[client_id].time_ > time - current_time_) {
            hotel_db_[client_id].rooms_count_ += room_count;
        } else{
            hotel_db_[client_id] = {time,room_count};
        }

    }

    size_t clients() const {
        auto clients_count{0};
        for (auto & [key,value]: hotel_db_) {
            if (value.time_ > current_time_ - 86'400) {
                ++clients_count;
            }
        }
        return clients_count;


    }
    size_t rooms() const {
        auto rooms_count{0};
        for (auto & [key,value]: hotel_db_) {
            if (value.time_ > current_time_ - 86'400) {
                rooms_count += value.rooms_count_;
            }
        }
        return rooms_count;
    }
    void update_current_time(int64_t current_time) {
        current_time_ = current_time;
    }

private:
    int64_t current_time_;
    std::unordered_map<int,BookingInfo> hotel_db_;
};



class BookingManager {

public:
    void book(int64_t time,const string& hotel_name,int client_id, int room_count){
        db_[hotel_name].add_entry(time,client_id,room_count);
        update_time(time);
    }
    int clients(const string& hotel_name) {
        if (db_.count(hotel_name)) {return db_[hotel_name].clients();}
        else return 0;
    }
    int rooms(const string& hotel_name) {
        if (db_.count(hotel_name)) {return db_[hotel_name].rooms();}
        else return 0;
    }
    void update_time(int64_t time){
        for (auto &[hotel_name, hotel_info]: db_) {
            hotel_info.update_current_time(time);
        }

    }
private:

    unordered_map<string,HotelInfo> db_;

};

#if 1

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

void test_double_booking(){
    BookingManager bm;
    bm.book(10,"FourSeasons",1,1);
    bm.book(20,"FourSeasons",1,2);
    bm.book(86405,"Martiott",1,1);
    ASSERT_EQUAL(bm.clients("FourSeasons"),1);
    ASSERT_EQUAL(bm.rooms("FourSeasons"),3);
}

#endif
void run_tests(){
    TestRunner tr;
    RUN_TEST(tr,test_example);
    RUN_TEST(tr,test_clients_count);
    RUN_TEST(tr,test_double_booking);


}

int main(){

    run_tests();

#if 0
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
