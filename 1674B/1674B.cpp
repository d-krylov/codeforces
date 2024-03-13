#include <iostream>
#include <string>

using namespace std;

int main() {
  uint32_t t;
  string s;
  cin >> t;
  for (uint32_t i = 0; i < t; i++) {
    cin >> s;
    uint32_t ret = 25 * s[0] + s[1] - 26 * 'a' + (s[0] >= s[1]);
    cout << ret << endl;
  }
}