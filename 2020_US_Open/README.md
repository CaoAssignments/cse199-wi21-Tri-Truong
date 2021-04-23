# Problem 1:
## Topics: Binary search, Greedy
## Problem formulation:  
Given N points (2 <= N <= 10^5) and M intervals (1 <= M <= 10^5). Return the maximum value of D where D is the distance between 2 closest points and all N points are on the M intervals. Note: for any interval (a,b), 0 <= a <= b <= 10^18.
## Solution:
Do binary search on the value of D (0 <= D <= 10^18). For each value of D, we can check if we can place N points on M intervals where the min distance between any 2 points is D through a greedy strategy: place each point at the left most position position possible.
## Time complexity:
O(NlogN + (N+M)log(max_dist)) = O((N+M)log(max_dist)) where max_dist = 10^18.
# Problem 2:
## Topics: Simulation, Recursion
## Problem formulation: 
Given M cereal boxes 1,2,...,M (1 <= M <= 10^5). Given N cows with preferences (f, s) with (1 <= N <= 10^5) and 1 <= f,s <= M. The order of those cows is kept as given in the input. The procedure: We go through the list of cows from left to right, a cow with preference (f,s) performs the following process when it is their turn:  
    1. If f is still available, take f  
    2. If f is not available but s is, take s  
    3. Otherwise, do nothing  
For each i, return the number of cwos that are able to take a cereal box if the first i cows are removed from the line.
## Solution:
Simulate the action of the cows in order, keep track of which boxes of cereal are left. For each i, simulate the last N - i cows. For each cow, checking if their prefereces are still there takes O(1) if we use an array of length M to represent the cereal boxes availablity.

If we follow the steps described above, time complexity is O(N^2).  
(10^5)^2 = 10^10 > 10^9 => too slow  

Opimization: Start with i = N and add cows on by one. Suppose we have solved the problem for the last N - i cows (we know which boxes the alst N-i cows would take). By adding one more cow (now we have N - i + 1 cows lined up, we can just efficiently update this result by computing how the box the new cow takes  would affect the outcome of the previous N - i cows. Observation:   
- If the new cow's preference is (f,s), it would certainly get f because it is in the front  
- If the last N-i cows didn't take f, nothing changes.
- If some cow j had taken f, after adding the new cow, j no longer has f.  
- If f is j's second choice, now j gets nothing. Everything else stays the same.
- If f is j's first choice and its second choice was taken by some cow earlier in line, j gets nothing. Everything else stays the same.  
- If j's second choice was not taken by some cow earlier, j will take it. This step requires us to do recursion on j to find out if j steals its 2nd choice cereal from some other cow later in line.  
Time complexity: O(N) because the sum of the recursion depths is O(N)
# Problem 3:
# Topic: Graph, Sorting
## Problem formulation:
Given N (1 <= N <= 10^5) pairs of integers. These pairs can interact with each other. The interaction is as follows: for any 2 pairs of integers (x_i, y_i) and (x_j, y_j), with -10^9 <= x,y <= 10^9 if x_i <= x_j and y_i <= y_j, one of the 2 pairs disappear. Return the min number of pairs left at the end.
## Solution: 
    1. Create an undirected graph where each vertex represents a pair
    and there exists an edge between 2 pairs if they satisfy the condition
    to interact.  
    2. Within each connected component, at least one pair must remain
    (since one pair must remain after any interaction)
    => Compute the number of connected components in this graph  
    
    Algorithm 1: build an adjacent list/graph and do DFS on it
    Time complexity: O(N^2) because it takes O(N^2) to build the graph
    N is maximum 10^5 => N^2 = 10^10 > 10^9 (rule of thumb) 
    => need a faster algorithm  
    
    Algorithm 2:  
    Observation: If we sort the pairs in increasing order of x and then y.
    Initially, each pair can be considered its own connected component.
    While there exist 2 connected componenents that are adjacent in the order
    such that min(y) of left component <= max(y) of right component, combine
    them.  
    1. Sort the pairs in increasing order of x and then y.  
    2. Compute min_left where min_left[i] = min y value up to i position from the left  
    3. Compute max_right where max_right[i] = max y value up to i position from the right  
    4. For loop i from 0 to N-2, if min_left[i] > max_right[i], increment ans  
    5. Return ans  
Time complexity: O(N)
