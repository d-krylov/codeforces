#include <iostream>

using namespace std;

int main() {
  uint32_t t, a, b, c;
  cin >> t;
  for (uint32_t i = 0; i < t; i++) {
    cin >> a >> b >> c;
    bool x = (b + c) % 2 == 0;
    bool y = (a + c) % 2 == 0;
    bool z = (a + b) % 2 == 0;
    cout << x << " " << y << " " << z << endl;
  }
}