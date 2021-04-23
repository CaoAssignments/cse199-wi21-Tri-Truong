#include <utility>
#include <map>
#include <stack>
#include <cstdlib>
#include <stdexcept>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdarg>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("paintbarn.in","r",stdin);
    freopen("paintbarn.out","w",stdout);
    // DP, Prefix Sum
    
    // Given N rectangles (1 <= N <= 10^5), each with sides parallel to
    // the coordinate axes, each described by the coordinates of its lower-left
    // and upper-right corner points, the coordinate values are in the range
    // 0 <= x,y <= 1000. Return the area covered with exactly K coats of paint
    // painted with (1 <= K <= 10^5), K is given as input.
    //
    // Soln:
    // 

    int n, k, dp[1005][1005];
    cin >> n >> k;
    while(n--) {
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      for(int i = a; i < c; i++) {
        dp[i][b]++;
        dp[i][d]--;
      }
    }
    int ret = 0;
    for(int i = 0; i < 1000; i++) {
      for(int j = 0; j < 1000; j++) {
        if(dp[i][j] == k) ret++;
        dp[i][j+1] += dp[i][j];
      }
    }
    cout << ret << endl;
}
