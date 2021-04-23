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

const int MAXN = 100000;

int N;
int x[MAXN], y[MAXN];
int cid[MAXN];
int min_left[MAXN];
int max_right[MAXN];
 
bool cmp(int a,int b)
{
    if(x[a]==x[b]) return y[a]<y[b];
    return x[a]<x[b];
}

int main() {
    // Graph, Sorting
    freopen("moop.in","r",stdin);
    freopen("moop.out","w",stdout);
    
    // Given N (1 <= N <= 10^5) pairs of integers. 
    // For any 2 pairs of integers (x_i, y_i) and (x_j, y_j),
    // with -10^9 <= x,y <= 10^9 if x_i <= x_j and y_i <= y_j, 
    // one of the 2 pairs
    // disappear. Return the min number of pairs left at the end.
    //
    // Soln: 
    // 1. Create an undirected graph where each vertex represents a pair
    // and there exists an edge between 2 pairs if they satisfy the condition
    // to interact.
    // 2. Within each connected component, at least one pair must remain
    // (since one pair must remain after any interaction)
    // => Compute the number of connected components in this graph
    //
    // Algorithm 1: build an adjacent list/graph and do DFS on it
    // Time complexity: O(N^2) because it takes O(N^2) to build the graph
    // N is maximum 10^5 => N^2 = 10^10 > 10^9 (rule of thumb) 
    // => need a faster algorithm
    // 
    // Alg 2:
    // Observation: If we sort the pairs in increasing order of x and then y.
    // Initially, each pair can be considered its own connected component.
    // While there exist 2 connected componenents that are adjacent in the order
    // such that min(y) of left component <= max(y) of right component, combine
    // them.
    // 1. Sort the pairs in increasing order of x and then y.
    // 2. Compute min_left where min_left[i] = min y value up to i position from the left
    // 3. Compute max_right where max_right[i] = max y value up to i position from the right
    // 4. For loop i from 0 to N-2, if min_left[i] > max_right[i], increment ans
    // 5. Return ans
    //
    // Time complexity: O(N)
    freopen("moop.in","r",stdin);
    freopen("moop.out","w",stdout);

    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> x[i] >> y[i];
        cid[i] = i;
    }
    sort(cid,cid+N,cmp);
    min_left[0] = y[cid[0]];
    for(int i=1;i<N;i++){
        min_left[i] = min(min_left[i-1], y[cid[i]]);
    }
    max_right[N-1] = y[cid[N-1]];

    for(int i=N-2;i>=0;i--){
        max_right[i] = max(max_right[i+1], y[cid[i]]);
    }

    int ans = 1;
    for(int i=0;i<N-1;i++){
        if(min_left[i] > max_right[i+1]){
            ans++;
        }
    }
    cout << ans << '\n';
}