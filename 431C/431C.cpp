#include <algorithm>
#include <iostream>

using namespace std;

constexpr uint64_t M = 1000000007;

int main() {
  uint32_t n, k, d;
  cin >> n >> k >> d;
  uint64_t P[n + 1][2];
  P[0][0] = 1;
  P[0][1] = 0;
  for (uint32_t i = 1; i <= n; i++) {
    P[i][0] = P[i][1] = 0;
    for (uint32_t j = 1; j <= min(k, i); j++) {
      P[i][0] += P[i - j][0] * (j < d);
      P[i][0] %= M;
      P[i][1] += P[i - j][1] + (j >= d) * P[i - j][0];
      P[i][1] %= M;
    }
  }
  cout << P[n][1] << endl;
}