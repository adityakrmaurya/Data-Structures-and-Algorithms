#include <iostream>
#include <string>

using std::string;


struct Query {
  string name = "not found";
  int number = -1;
};

void read_queries() {
  int n;
  std::cin >> n;
  Query* queries = nullptr;
  queries = new Query[10000000];
  for (int i = 0; i < n; ++i) {
    string type_query;
    int phone;
    std::cin >> type_query;
    std::cin >> phone;
    if (type_query == "add") {
      queries[phone].number = phone;
      std::cin >> queries[phone].name;
    } 
    else if (type_query == "del") {
      queries[phone].number = -1;
      queries[phone].name = "not found";
    }
    else {
      std::cout << queries[phone].name << std::endl;
    }
  }
  delete [] queries;
}

int main() {
  read_queries();
  return 0;
}
