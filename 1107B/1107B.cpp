#include <iostream>

using namespace std;

int main() {
  uint64_t n, k, x;
  cin >> n;
  for (uint64_t i = 0; i < n; i++) {
    cin >> k >> x;
    auto ret = 9 * (k - 1) + x;
    cout << ret << endl;
  }
}