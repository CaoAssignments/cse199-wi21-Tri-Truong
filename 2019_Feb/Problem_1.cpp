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

int N, A[100000];

int solve_min(){
  if (A[N-2]-A[0] == N-2 && A[N-1]-A[N-2]>2) return 2;
  if (A[N-1]-A[1] == N-2 && A[1]-A[0]>2) return 2;

  int i, j=0, best = 0;

  for (i=0; i<N; i++) {
    while (j<N-1 && A[j+1]-A[i]<=N-1) j++;

    best = max(best, j-i+1);
  }

  return N-best;
}

int main() {
    freopen("herding.in","r",stdin);
    freopen("herding.out","w",stdout);
    // Sliding window, Sorting
    
    // Given N cows on a number line. At any point, we can make a move by picking a cow at an "endpoint" - the largest or smallest number
    // and move it to a number that is currently not occupied and not an endpoint.
    // Find the maximum and minimum number of moves before the cows become grouped in N
    // of consecutive locations.
    //
    // Soln: We need to solve 2 problems: min and max
    // - For the min, we want to look for the N-length window containing the most cows
    // (fewest empty spaces) because we can fill in the x empty spaces in the window
    // with exactly x moves.
    // - For the max, it is the difference between the biggest gap possible and the
    // number of cows that are not already at the 2 end points
    // => Formula: max(A[N-2] - A[0], A[N-1]-A[1]) - (N-2)
    // Time complexity: O(NlogN)
    cin >> N; 
    for (int i=0; i<N; i++) cin >> A[i];
    sort (A, A+N);
 
    int answer_min = solve_min();
    int answer_max = max(A[N-2]-A[0], A[N-1]-A[1]) - (N-2);
    cout << answer_min << "\n" << answer_max << "\n";
    return 0;
}
