#include <iostream>
#include <vector>

using namespace std;

int main() {
  uint32_t n, total = 0, current = 0, ret = 0;
  cin >> n;
  vector<int> v(n, 0);
  for (auto &x : v) {
    std::cin >> x;
    total += x;
  }
  for (uint32_t i = 0; i < n; i++) {
    current += v[i];
    ret = i + (2 * current == total);
    if (2 * current == total) {
      break;
    } else if (2 * current > total) {
      ret += (2 * current <= v[i] + total);
      break;
    }
  }
  if (n < 3) {
    ret = 1;
  }
  cout << ret << ' ' << (n - ret) << endl;
}