#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using Pair = pair<uint32_t, uint32_t>;

constexpr uint32_t N = 9;

int main() {
  uint32_t v;
  cin >> v;
  vector<Pair> colors(N);
  for (uint32_t i = 0; i < colors.size(); i++) {
    colors[i].first = i + 1;
    cin >> colors[i].second;
  }
  auto Compare = [](const Pair &a, const Pair &b) {
    return (a.second < b.second);
  };
  vector<Pair> sorted_colors = colors;
  sort(sorted_colors.begin(), sorted_colors.end(), Compare);
  auto length = v / sorted_colors[0].second;
  string ret(length, sorted_colors[0].first + '0');
  if (length != 0) {
    auto total = length * sorted_colors[0].second;
    for (uint32_t i = 0; i < length; i++) {
      for (auto x : sorted_colors) {
        if (x.first > colors[ret[i] - '1'].first) {
          auto digit = total - colors[ret[i] - '1'].second + x.second;
          if (digit <= v) {
            ret[i] = x.first + '0';
            total = digit;
          }
        }
      }
    }
  } else {
    std::cout << "-1" << std::endl;
  }
  cout << ret << endl;
}