#include <iostream>
#include <vector>

using namespace std;

uint32_t q[] = {0, 1, 2, 1, 2, 3, 1, 2, 3, 2, 1, 2, 2, 2, 3,
                1, 2, 3, 2, 3, 2, 2, 3, 3, 3, 2, 3, 3, 3, 4};

int main() {
  uint32_t t, n;
  cin >> t;
  vector<uint32_t> ret(t);
  for (uint32_t i = 0; i < t; i++) {
    cin >> n;
    ret[i] = q[n % 30] * (n < 30) + ((n / 15 - 1) + q[n % 15 + 15]) * (n >= 30);
  }
  for (auto x : ret) {
    cout << x << endl;
  }
}