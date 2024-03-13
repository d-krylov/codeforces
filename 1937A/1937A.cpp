#include <iostream>
#include <vector>

using namespace std;

int main() {
  uint32_t t, n, power;
  cin >> t;
  vector<uint32_t> ret(t);
  for (uint32_t i = 0; i < t; i++) {
    cin >> n;
    power = 1;
    while (power * 2 <= n) {
      power *= 2;
    }
    ret[i] = power;
  }
  for (auto x : ret) {
    cout << x << endl;
  }
}