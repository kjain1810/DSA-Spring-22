#include <bits/stdc++.h>

using namespace std;

// vector
// push_back
// size
vector<int> adj[20001];
// queue
// push
// pop
// front
// size
queue<int> q;
// stack
// priority_queuue

int n, m, degree[200005];
int visited[200005];

void bfs(int st) {
  visited[st] = 1;
  q.push(st);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int a = 0; a < adj[u].size(); a++) {
      int v = adj[u][a];
      if (visited[v])
        continue;
      visited[v] = 1;
      q.push(v);
      cout << u << " " << v << endl;
    }
  }
}

int main() {
  cin >> n >> m;
  int maxi = 0;
  int maxi_node = -1;
  for (int a = 0; a < m; a++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    degree[u]++;
    degree[v]++;
  }
  for (int a = 1; a <= n; a++)
    if (adj[a].size() > maxi) {
      maxi = adj[a].size();
      maxi_node = a;
    }
  bfs(maxi_node);
  return 0;
}
