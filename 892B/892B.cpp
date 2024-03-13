#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  uint32_t n, ret, left;
  cin >> n;
  ret = left = n;
  vector<uint32_t> L(n);
  for (auto &x : L) {
    cin >> x;
  }
  for (int32_t i = n - 1; i >= 0; i--) {
    ret -= (i >= left);
    if (i > L[i]) {
      left = min(left, i - L[i]);
    } else {
      ret -= i;
      break;
    }
  }
  cout << ret << endl;
}