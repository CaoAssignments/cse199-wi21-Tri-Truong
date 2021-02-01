/* prefix sum */
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

using namespace std;

#define MAXN 100007

int prefix_sum[MAXN * 2];

int main() {
  freopen("fairphoto.in", "r", stdin);
  freopen("fairphoto.out", "w", stdout);

  int N; cin >> N;
  vector<pair<int, char> > A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i].first >> A[i].second;
  }
  A.push_back(make_pair(1000000010, '?'));
  sort(A.begin(), A.end());

  int res = 0;
  for(int i = 0; i < N; ) {
    int sz = 1;
    while(i + sz < N && A[i].second == A[i + sz].second) {
      ++sz;
    }
    res = max(res, A[i + sz - 1].first - A[i].first);
    i += sz;
  }

  int psm = 0;
  memset(prefix_sum, 0x3F, sizeof(prefix_sum));
  for(int i = 0; i < N; i++) {
    prefix_sum[N + psm] = min(prefix_sum[N + psm], A[i].first);
    psm += A[i].second == 'G' ? 1 : -1;
    res = max(res, A[i].first - prefix_sum[N + psm]);
  }

  cout << res << endl;
  return 0;
}