#include <iostream>

using namespace std;

constexpr uint64_t M = 1000000007;

uint64_t GetFactorial(uint32_t n) {
  uint64_t ret = 1;
  for (uint64_t i = 3; i <= n; i++) {
    ret = (ret * i) % M;
  }
  return ret;
}

int main() {
  uint32_t t, n;
  cin >> t;
  for (uint32_t i = 0; i < t; i++) {
    cin >> n;
    auto ret = GetFactorial(2 * n);
    cout << ret << endl;
  }
}