#include "../test_runner.h"
#include <iostream>
#include <vector>
#include <set>

using namespace std;


class StringSet {
public:
    void Add(const string & str,int priority) {
        sorted_.insert({str,priority});
        data_.push_back(str);
    }
    const string& FindLast() const {
        return data_.back();
    }
    const string & FindBest() const {
        return prev(sorted_.end())->str_;
    }

private:
    vector<string> data_;
    struct StringItem {
        bool operator<(const StringItem & other) const {
            return priority_ < other.priority_;
        }
        string str_;
        int priority_;

    };
    set<StringItem> sorted_;

};



void TestSimple() {
    StringSet strings;
    strings.Add("upper", 10);
    strings.Add("lower", 0);
    ASSERT_EQUAL(strings.FindLast(), "lower");
    ASSERT_EQUAL(strings.FindBest(), "upper");
}

void TestAnother() {
    StringSet strings;

    strings.Add("apple", 1);
    strings.Add("orange", 3);
    ASSERT_EQUAL(strings.FindLast(), "orange");
    ASSERT_EQUAL(strings.FindBest(), "orange");

    strings.Add("plum", -5);
    ASSERT_EQUAL(strings.FindLast(), "plum");
    ASSERT_EQUAL(strings.FindBest(), "orange");

    strings.Add("lemon", 5);
    ASSERT_EQUAL(strings.FindLast(), "lemon");
    ASSERT_EQUAL(strings.FindBest(), "lemon");
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestSimple);
    RUN_TEST(tr, TestAnother);
    return 0;
}