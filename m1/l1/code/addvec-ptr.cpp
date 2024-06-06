#include <thread>
#include <iostream>
#include <vector>
#include <numeric>

void add_vector(const std::vector<int> & v, int *r) {
  *r = std::accumulate(v.begin(), v.end(), 0);
}

void f() {
  using namespace std;
  vector<int> w1 {1, 2, 4, 8, 16};
  vector<int> w2 {2, 4, 6, 8, 10};
  int x1, x2;
  thread t1{add_vector, w1, &x1};
  thread t2{add_vector, w2, &x2};
  t1.join();
  t2.join();
  cout << "x1 -> " << x1 << " x2 -> " << x2 << endl;
}

int main() {
  f();
}
