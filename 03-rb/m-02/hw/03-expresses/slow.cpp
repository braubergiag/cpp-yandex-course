#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>

using namespace std;


struct RouteInfo {
  int start;
  int finish;
  size_t reachable_size;
};
set<int>::const_iterator FindNearestElement(const set<int> & elements, int border){
    if (elements.empty()) return end(elements);
    auto [lb,ub] = elements.equal_range(border);

    if (*lb == border) return lb;
    else lb = prev(lb);

    if (abs(border - *lb) <= abs(border - *ub)) return lb;
    else return ub;

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


int main() {
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

  return 0;
}
