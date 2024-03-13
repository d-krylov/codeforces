#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  uint32_t n, d;
  int32_t ret = -1;
  cin >> n;
  set<uint32_t> s;
  for (uint32_t i = 0; i < n; i++) {
    cin >> d;
    s.insert(d);
  }
  if (s.size() == 2) {
    vector<uint32_t> v(s.begin(), s.end());
    ret = v[1] - v[0];
    ret >>= 1 - ret % 2;
  } else if (s.size() == 3) {
    vector<uint32_t> v(s.begin(), s.end());
    if (2 * v[1] == v[0] + v[2]) {
      ret = v[1] - v[0];
    }
  } else if (s.size() == 1) {
    ret = 0;
  }
  cout << ret << endl;
}