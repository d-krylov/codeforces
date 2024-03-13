#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool Get(const vector<string> &v) {
  auto size = v.size() - 1;
  for (uint32_t row = 0; row < size; row++) {
    for (uint32_t column = 0; column < size; column++) {
      if (v[row][column] == '1') {
        auto b = (v[row + 1][column] == '1') || (v[row][column + 1] == '1');
        if (b == false) {
          return false;
        }
      }
    }
  }
  return true;
}

int main() {
  uint32_t t, n;
  cin >> t;
  vector<string> ret(t);
  for (uint32_t i = 0; i < t; i++) {
    cin >> n;
    vector<string> P(n);
    for (uint32_t j = 0; j < n; j++) {
      cin >> P[j];
    }
    if (n == 1) {
      ret[i] = "YES";
    } else {
      ret[i] = Get(P) ? "YES" : "NO";
    }
  }
  for (auto x : ret) {
    cout << x << endl;
  }
}