#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m;
vector<int> graph[1001];
int visited[1001];
int result = 0;
void solution(int now) {
  if (visited[now] == 1) {
    return;
  }
  visited[now] = 1;
  for (int i = 0; i < graph[now].size(); i++) {
    // cout << graph[now][i] << " " << now << "\n";
    if (visited[graph[now][i]] != 1) {
      // cout << graph[now][i] << "\n";
      solution(graph[now][i]);
    }
  }
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for (int i = 1; i <= n; i++) {
    if (visited[i] == 1)
      continue;
    solution(i);
    // for (int i = 1; i <= n; i++) {
    //   cout << visited[i] << " ";
    // }
    // cout << "\n";
    result++;
  }

  cout << result << "\n";
  return 0;
}