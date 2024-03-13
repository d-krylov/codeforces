#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  uint32_t n, x, y;
  cin >> n;
  vector<vector<uint32_t>> tree(n);
  for (uint32_t i = 0; i < n - 1; i++) {
    cin >> x >> y;
    tree[x - 1].emplace_back(y - 1);
    tree[y - 1].emplace_back(x - 1);
  }
  vector<uint32_t> colors(n, 1);
  vector<uint32_t> parent(n, 0);
  vector<uint32_t> visit(n, 0);
  queue<uint32_t> q;

  q.push(0);
  colors[0] = 1;
  visit[0] = 1;

  while (q.empty() == false) {
    auto vertex = q.front();
    q.pop();
    auto degree = tree[vertex].size();
    uint32_t current_color = 1;
    for (auto &neighbour : tree[vertex]) {
      if (visit[neighbour] == 0) {
        visit[neighbour] = 1;
        current_color += (colors[vertex] == current_color) ||
                         (colors[parent[vertex]] == current_color);
        current_color += (colors[vertex] == current_color) ||
                         (colors[parent[vertex]] == current_color);
        colors[neighbour] = current_color++;
        parent[neighbour] = vertex;
        q.push(neighbour);
      }
    }
  }
  auto ret = max_element(colors.begin(), colors.end());
  cout << *ret << endl;
  for (auto x : colors) {
    cout << x << " ";
  }
}