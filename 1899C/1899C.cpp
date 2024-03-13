#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int32_t Get(uint32_t n) {
  int32_t current, previous;
  cin >> previous;
  int32_t ret = previous;
  int32_t sum = max(ret, 0);
  for (uint32_t i = 1; i < n; i++) {
    cin >> current;
    if ((current - previous) % 2 == 0) {
      sum = 0;
    }
    sum += current;
    ret = max(ret, sum);
    sum = max(sum, 0);
    previous = current;
  }
  return ret;
}

int main() {
  uint32_t t, n;
  cin >> t;
  vector<int32_t> ret(t, 0);
  for (uint32_t i = 0; i < t; i++) {
    cin >> n;
    ret[i] = Get(n);
  }
  for (auto x : ret) {
    cout << x << endl;
  }
}