#include <iostream>
#include <map>

using namespace std;


class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    first_names_db_[year] = first_name;
    // добавить факт изменения имени на first_name в год year
  }
  void ChangeLastName(int year, const string& last_name) {
    last_names_db_[year] = last_name;
    // добавить факт изменения фамилии на last_name в год year
  }
  string GetFullName(int year) {


    string name, last_name;

    auto it_name = first_names_db_.upper_bound(year);
    auto it_last_name = last_names_db_.upper_bound(year);

    if (!first_names_db_.empty()){
        it_name = prev(it_name);
    } 
      
    if (!last_names_db_.empty()) it_last_name = prev(it_last_name);


    if (it_name->first > year && it_last_name->first > year){
        return "Incognito";
    } else if (it_name->first <= year && it_last_name->first > year){
        return it_name->second + " with unknown last name";
    } else if (it_name->first > year && it_last_name->first <= year){
        return it_last_name->second + " with unknown first name";
    } else if (it_name->first <= year && it_last_name->first <= year){
        return it_name->second + " " + it_last_name->second;
    }
    // получить имя и фамилию по состоянию на конец года year
    // с помощью двоичного поиска
  }
private:
    map<int,string> first_names_db_;
    map<int,string> last_names_db_;
  // приватные поля
};


int main(){

     Person person;

     person.GetFullName(1223);
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  return 0;

}