
#include <bits/stdc++.h>

using namespace std;

// vector
// push_back
vector<int> adj[10001];
int visited[10001];

// queue
// stack
// priority_queuue

int N, M;

void dfs(int u) {
  if (visited[u] == 1) {
    return;
  }
  cout << endl;
  visited[u] = 1;
  for (int i = 0; i < adj[u].size(); i++) {
    int c = adj[u][i];
    dfs(c);
  }
}

int main() {

  cin >> N >> M;
  int cnt = 0;
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1);

  int all_visited = true;
  for (int i = 1; i <= N; i++) {
    if (visited[i] == 0) {
      all_visited = false;
    }
  }
  if (all_visited && M == N - 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO\n";
  }
  return 0;
}
