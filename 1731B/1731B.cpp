#include <iostream>
#include <vector>

using namespace std;

constexpr uint64_t M = 1000000007;

int main() {
  uint64_t t, n;
  cin >> t;
  for (uint32_t i = 0; i < t; i++) {
    cin >> n;
    uint64_t ret = ((337 * n) % M) * ((4 * n * n + 3 * n - 1) % M);
    ret %= M;
    cout << ret << endl;
  }
}