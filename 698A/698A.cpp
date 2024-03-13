#include <algorithm>
#include <array>
#include <iostream>

using namespace std;

int main() {
  uint32_t n;
  uint32_t s;
  cin >> n;
  array<uint32_t, 3> current{0, 0, 0};
  array<uint32_t, 3> previous{0, 0, 0};
  for (uint32_t i = 0; i < n; i++) {
    cin >> s;
    current[0] = max({previous[0], previous[1], previous[2]});
    if (s == 1 || s == 3) {
      current[1] = max(previous[0], previous[2]) + 1;
    }
    if (s == 2 || s == 3) {
      current[2] = max(previous[0], previous[1]) + 1;
    }
    swap(current, previous);
  }
  uint32_t m = max({previous[0], previous[1], previous[2]});
  cout << (n - m) << endl;
}