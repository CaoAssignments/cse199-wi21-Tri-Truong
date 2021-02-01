/* graph processing and coloring graphs */
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <map>
#include <stack>
#include <cmath>
#include <climits>
#include <cstring>

using namespace std;


#define MAXN 50007

int color[MAXN];
int color_cnt[2];
vector<int> graph[MAXN];

bool dfs(int u, int c) {
  if(color[u] != -1) return color[u] == c;
  color[u] = c;
  color_cnt[c]++;

  for(int i = 0; i < graph[u].size(); i++) {
    if(!dfs(graph[u][i], 1 - c)) {
      return false;
    }
  }

  return true;
}

int main() {
  freopen("decorate.in", "r", stdin);
  freopen("decorate.out", "w", stdout);

  int N, M;
  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;

    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  int cnt = 0;
  int result = 0;
  memset(color, -1, sizeof(color));
  for(int i = 0; i < N; i++) {
    if(color[i] != -1) continue;
    cnt++;
    color_cnt[0] = 0;
    color_cnt[1] = 0;
    if (!dfs(i, 0)) {
      result = -1;
      break;
    }
    result += max(color_cnt[0], color_cnt[1]);
  }
  cout << result << endl;

  return 0;
}