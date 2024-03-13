#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

constexpr uint64_t M = 1000000007;

uint64_t BinomialCoefficient(uint64_t n, uint64_t k) {
  vector<uint64_t> C(k + 1, 0);
  C[0] = 1;
  for (uint64_t i = 1; i <= n; i++) {
    for (uint64_t j = min(i, k); j > 0; j--) {
      C[j] = (C[j] + C[j - 1]) % M;
    }
  }
  return C[k];
}

int main() {
  uint32_t n, m;
  cin >> n >> m;
  auto ret = BinomialCoefficient(n + 2 * m - 1, 2 * m);
  cout << ret << endl;
}