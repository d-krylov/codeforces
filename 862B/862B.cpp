#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  uint32_t n, x, y;
  cin >> n;
  vector<vector<uint32_t>> tree(n);
  for (uint32_t i = 0; i < (n - 1); i++) {
    cin >> x >> y;
    tree[x - 1].emplace_back(y - 1);
    tree[y - 1].emplace_back(x - 1);
  }
  vector<uint32_t> group(n, 0);
  vector<uint32_t> visit(n, 0);
  queue<uint32_t> q;

  q.push(0);
  visit[0] = 1;

  while (q.empty() == false) {
    auto current = q.front();
    q.pop();
    for (auto x : tree[current]) {
      if (visit[x] == 0) {
        visit[x] = 1;
        group[x] = group[current] ^ 1;
        q.push(x);
      }
    }
  }
  uint32_t first_group = count(group.begin(), group.end(), 0);
  uint32_t second_group = n - first_group;
  uint32_t result = first_group * second_group - n + 1;

  cout << result << endl;
}