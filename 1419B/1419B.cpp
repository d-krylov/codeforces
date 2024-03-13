#include <iostream>

using namespace std;

int main() {
  int64_t t, x, ret;
  cin >> t;
  for (uint64_t i = 0; i < t; i++) {
    cin >> x;
    for (int64_t j = 1; j < 64; j++) {
      x -= ((1ULL << j) - 1) * (1ULL << (j - 1));
      if (x < 0) {
        ret = j - 1;
        break;
      }
    }
    cout << ret << endl;
  }
}