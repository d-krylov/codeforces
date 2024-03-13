#include <iostream>
#include <vector>

using namespace std;

int main() {
  uint32_t t, n;
  cin >> t;
  vector<uint32_t> ret(t, 0);
  for (uint32_t i = 0; i < t; i++) {
    cin >> n;
    uint32_t current, previous = 0;
    uint32_t count = 0;
    for (uint32_t j = 0; j < n; j++) {
      cin >> current;
      if (current < previous) {
        count++;
        previous = 0;
      } else {
        previous = current;
      }
    }
    ret[i] = count;
  }
  for (auto x : ret) {
    cout << x << endl;
  }
}