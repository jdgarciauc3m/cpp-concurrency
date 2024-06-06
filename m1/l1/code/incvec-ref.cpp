#include <thread>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void inc_vector(std::vector<int> & v) { //not const reference
  std::for_each(v.begin(), v.end(), [](int& i){++i;});
}

void f() {
  using namespace std;
  vector<int> w1 {1, 2, 4, 8, 16};
  //thread t1{inc_vector, w1}; //this does not compile because v is not a lvalue ref to const.
  // thread copies w1 and later pass it as an rvalue, but v is lvalue ref to non-const --> wrong 
  thread t2{inc_vector, ref(w1)};
  t2.join();
  cout << "w1[0] -> " << w1[0] << " w1[1] -> " << w1[1] << endl;

}

int main() {
  f();
}
