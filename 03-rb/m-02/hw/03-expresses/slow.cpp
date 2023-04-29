#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <random>
//#include "../test_runner.h"

using namespace std;


set<int>::const_iterator FindNearestElement(const set<int> & elements, int border){
    if (elements.empty()) return end(elements);
    auto [lb,ub] = elements.equal_range(border);

    if (lb == end(elements)) {
        return prev(lb);
    } else if (lb != begin(elements) && (abs(*prev(lb) - border) <= abs(*lb - border))) {
        return prev(lb);
    } else return lb;

}
class RouteManager {
public:
  void AddRoute(int start, int finish) {
    reachable_lists_[start].insert(finish);
    reachable_lists_[finish].insert(start);
  }
  int FindNearestFinish(int start, int finish) const {
    int result = abs(start - finish);
    if (reachable_lists_.count(start) < 1) {
        return result;
    }
    const set<int>& reachable_stations = reachable_lists_.at(start);
    if (reachable_stations.count(finish)) return 0;

    if (!reachable_stations.empty()) {
      result = min( result,abs(*FindNearestElement(reachable_stations, finish) - finish));
    }
    return result;
  }
private:
  map<int, set<int>> reachable_lists_;
};
class RouteManagerSlow {
public:
  void AddRoute(int start, int finish) {
    reachable_lists_[start].push_back(finish);
    reachable_lists_[finish].push_back(start);
  }
  int FindNearestFinish(int start, int finish) const {
    int result = abs(start - finish);
    if (reachable_lists_.count(start) < 1) {
        return result;
    }
    const vector<int>& reachable_stations = reachable_lists_.at(start);
    if (!reachable_stations.empty()) {
      result = min(
          result,
          abs(finish - *min_element(
              begin(reachable_stations), end(reachable_stations),
              [finish](int lhs, int rhs) { return abs(lhs - finish) < abs(rhs - finish); }
          ))
      );
    }
    return result;
  }
private:
  map<int, vector<int>> reachable_lists_;
};


#if 0

void test_1(){
  RouteManagerFast routes;
  routes.AddRoute(-2,5);
  routes.AddRoute(10,4);
  routes.AddRoute(5,8);

  ASSERT_EQUAL(routes.FindNearestFinish(4,10),0);
  ASSERT_EQUAL(routes.FindNearestFinish(4,-2),6);
  ASSERT_EQUAL(routes.FindNearestFinish(5,0),2);
  ASSERT_EQUAL(routes.FindNearestFinish(5,100),92);
  ASSERT_EQUAL(routes.FindNearestFinish(4,9),1);
  ASSERT_EQUAL(routes.FindNearestFinish(4,11),1);
  ASSERT_EQUAL(routes.FindNearestFinish(10,2),2);

  ASSERT_EQUAL(routes.FindNearestFinish(-2,-2),0);
  ASSERT_EQUAL(routes.FindNearestFinish(-2,-3),1);
  ASSERT_EQUAL(routes.FindNearestFinish(-2,-4),2);
  ASSERT_EQUAL(routes.FindNearestFinish(-2,-5),3);
  ASSERT_EQUAL(routes.FindNearestFinish(-2,0),2);
  ASSERT_EQUAL(routes.FindNearestFinish(-2,1),3);
  ASSERT_EQUAL(routes.FindNearestFinish(-2,2),3);
  ASSERT_EQUAL(routes.FindNearestFinish(-2,3),2);
  ASSERT_EQUAL(routes.FindNearestFinish(-2,4),1);
  ASSERT_EQUAL(routes.FindNearestFinish(-2,5),0);
  ASSERT_EQUAL(routes.FindNearestFinish(-2,6),1);



  ASSERT_EQUAL(routes.FindNearestFinish(-1'000'000'000,1'000'000'000),2'000'000'000);



}


void test_3(){
  RouteManagerFast routes;
  routes.AddRoute(1,-2);
  routes.AddRoute(1,-4);
  routes.AddRoute(1,-6);

  ASSERT_EQUAL(routes.FindNearestFinish(1,8),7);
  ASSERT_EQUAL(routes.FindNearestFinish(1,-8),2);
}
  



void test_2(){
  RouteManagerFast routes;
  routes.AddRoute(1,2);
  routes.AddRoute(1,4);
  routes.AddRoute(1,6);

  routes.AddRoute(-1,-2);
  routes.AddRoute(-1,-4);
  routes.AddRoute(-1,-6);

  ASSERT_EQUAL(routes.FindNearestFinish(1,8),2);
  ASSERT_EQUAL(routes.FindNearestFinish(1,5),1);
  ASSERT_EQUAL(routes.FindNearestFinish(1,0),1);
  ASSERT_EQUAL(routes.FindNearestFinish(-1,-8),2);
  ASSERT_EQUAL(routes.FindNearestFinish(-1,-5),1);
  ASSERT_EQUAL(routes.FindNearestFinish(-1,0),1);

  ASSERT_EQUAL(routes.FindNearestFinish(-1,-1),0);
  ASSERT_EQUAL(routes.FindNearestFinish(-1,1),2);


}

void test_global(){


    int QUERIES_SIZE = 2000;
    int expresses_count = 1000;
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distrib_routes(-20000, 20000);

    std::uniform_int_distribution<> distrib_expresses(-20000, 20000);


    RouteManagerSlow route_mgr_slow;
    RouteManagerFast route_mgr_fast;

    for (int n = 0; n != expresses_count; ++n) {
        auto start = distrib_expresses(gen);
        auto finish =  distrib_expresses(gen);
        route_mgr_slow.AddRoute(start,finish);
        route_mgr_fast.AddRoute(start,finish);


    }


    for (int n = 0; n != QUERIES_SIZE; ++n) {
        auto start =  distrib_routes(gen);
        auto finish = distrib_routes(gen);

        auto slow_res = route_mgr_slow.FindNearestFinish(start,finish);
        auto fast_res = route_mgr_fast.FindNearestFinish(start,finish);
        ASSERT_EQUAL(slow_res,fast_res);
        #if 0
        if (slow_res !=  fast_res){
          auto res = route_mgr_fast.FindNearestFinish(start,finish);

        }
        #endif
   


    }
    

}

#endif
int main() {

#if 0
  TestRunner tr;
  RUN_TEST(tr,test_1);
  RUN_TEST(tr,test_2);
  RUN_TEST(tr,test_3);
    RUN_TEST(tr,test_global);

#endif
  #if 1
  RouteManager routes;

  int query_count;
  cin >> query_count;

  for (int query_id = 0; query_id < query_count; ++query_id) {
    string query_type;
    cin >> query_type;
    int start, finish;
    cin >> start >> finish;
    if (query_type == "ADD") {
      routes.AddRoute(start, finish);
    } else if (query_type == "GO") {
      cout << routes.FindNearestFinish(start, finish) << "\n";
    }
  }
  #endif

  return 0;
}
