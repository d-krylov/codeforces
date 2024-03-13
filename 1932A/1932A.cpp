#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  uint32_t t;
  cin >> t;
  vector<uint32_t> ret(t);
  for (uint32_t i = 0; i < t; i++) {
    uint32_t n;
    string s;
    cin >> n;
    cin >> s;
    char previous = '.';
    uint32_t count = 0;
    for (char c : s) {
      if (c == '*' && previous == '*') {
        break;
      }
      if (c == '@') {
        count++;
      }
      previous = c;
    }
    ret[i] = count;
  }
  for (auto x : ret) {
    cout << x << endl;
  }
}