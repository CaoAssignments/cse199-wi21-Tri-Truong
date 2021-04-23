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

int n, m;
const int INF = 1e9;
vector<pair<long long, long long>> intervals;

bool check_D(long long d) {
    long long prev = -1LL * INF * INF;
    
    int cnt = 0;
    for (auto& i : intervals) {
        while (max(prev + d, i.first) <= i.second) {
            prev = max(prev + d, i.first);
            cnt++;
            if (cnt >= n) break;
        }
        if (cnt >= n) break;
    }
 
    return (cnt >= n);
}

int main() {
    freopen("socdist.in","r",stdin);
    freopen("socdist.out","w",stdout);
    // Given N points (2 <= N <= 10^5) and M intervals (1 <= M <= 10^5)
    // Return the maximum value of D where D is the distance between
    // 2 closest points and all N points are on the M intervals.
    // Note: for any interval (a,b), 0 <= a <= b <= 10^18.
    //
    // Soln: Binary search the value of D (0 <= D <= 10^18).
    // For each value of D, we can check if we can place N points on M intervals
    // where the min distance between any 2 points is D.
    //
    // Alg:
    // 1. Sort the intervals from left to right
    // 2. For a value of D, we check if we can place N points through a greedy
    // strategy, just place each cow at the leftmost position possible. 
    // This can be done in O(M + N)
    //
    // Time complexity: O((N+M)log(10^18)) ~ 2*(10^5)*log(10^18) = 3.6 * 10^6
    // => acceptable
    cin >> n >> m;

    intervals.resize(m);
    for (int i = 0; i < m; ++i) 
        cin >> intervals[i].first >> intervals[i].second;
 
    sort(intervals.begin(), intervals.end());
 
    long long lo = 1;
    long long hi = 1LL * INF * INF;
    long long res = -1;
 
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
 
        if (check_D(mid)) {
            res = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
 
    cout << res << "\n";
}
