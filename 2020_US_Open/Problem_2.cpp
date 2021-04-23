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
const int MAXN = 1e5 + 5;

int main() {
    // Recursion, simulation
    //
    // Given M cereal boxes 1,2,...,M (1 <= M <= 10^5). 
    // Given N cows with preferences (f, s) with 
    // (1 <= N <= 10^5) and 1 <= f,s <= M. 
    // The order of those cows is kept as given in the input.
    // The procedure: We go through the list of cows from left
    // to right, a cow with preference (f,s) performs the following process 
    // when it is their turn:
    //  1. If f is still available, take f
    //  2. If f is not available but s is, take s 
    //  3. Otherwise, do nothing
    //
    // For each i, return the number of cows that are able to take a cereal box
    // if the first i cows are removed from the line.
    //
    // Soln: Simulate the action of the cows in order, keep track of which
    // boxes of cereal are left. For each i, simulate the last N - i cows.
    // For each cow, checking if their prefereces are still there takes O(1)
    // if we use an array of length M to represent the cereal boxes
    // availablity
    // 
    // Alg1: As described above, time complexity is O(N^2)
    // (10^5)^2 = 10^10 > 10^9 => too slow
    //
    // Optimization: Start with i = N and add cows on by one. Suppose we have solved the 
    // problem for the last N - i cows (we know which boxes the alst N-i cows
    // would take). By adding one more cow (now we have N - i + 1 cows lined
    // up, we can just efficiently update
    // this result by computing how the box the new cow takes 
    // would affect the outcome of the previous N - i cows.
    // Observation: 
    //  - If the new cow's preference is (f,s), it would certainly get f
    // because it is in the front
    //  - If the last N-i cows didn't take f, nothing changes.
    //  - If some cow j had taken f, after adding the new cow, j no longer has
    // f.
    //  - If f is j's second choice, now j gets nothing. Everything else stays
    // the same.
    //  - If f is j's first choice and its second choice was taken by some cow
    // earlier in line, j gets nothing. Everything else stays the same
    //  - If j's second choice was not taken by some cow earlier, j will take 
    // it. This step requires us to do recursion on j to find out if j
    // steals its 2nd choice cereal from some other cow later in line.
    //
    // Time complexity: O(N) because the sum of the recursion depths is O(N)
    freopen("cereal.in","r",stdin);
    freopen("cereal.out","w",stdout);
    // cereals[index] stores the index of the cow that gets cereal index
    int N, M, f[MAXN], s[MAXN], cereals[MAXN], ans[MAXN];

    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> f[i] >> s[i];
    }
    int cnt = 0;

    for(int i=N-1;i>=0;i--)
    {
        int j = i;
        int pos = f[i];
        while(1)
        {
            if(cereals[pos] == 0)
            {
                cereals[pos] = j;
                cnt++;
                break;
            }
            else if(cereals[pos] < j)
                break;
            else
            {
                int k = cereals[pos];
                cereals[pos] = j;
                if(pos == s[k])
                    break;
                j = k;
                pos = s[k];
            }
        }
        ans[i] = cnt;
    }
    for(int i=0;i<N;i++)
        cout << ans[i] << '\n';

}
