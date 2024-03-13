#include <iostream>

using namespace std;

constexpr uint64_t M = 1000000007;

uint64_t power(uint64_t a, uint64_t b) {
  if (b == 0) {
    return 1;
  }
  uint64_t ret = power(a, b / 2);
  ret = (ret * ret) % M;
  if (b % 2 != 0) {
    ret *= a;
  }
  return ret % M;
}

int main() {
  uint32_t n;
  cin >> n;
  uint64_t count = (1ULL << n) - 2;
  uint64_t ret = power(4, count);
  ret = (ret * 6) % M;
  cout << ret << endl;
}