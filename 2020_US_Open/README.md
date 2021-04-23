# Problem 1:
## Problem formulation:  
Given N points (2 <= N <= 10^5) and M intervals (1 <= M <= 10^5). Return the maximum value of D where D is the distance between 2 closest points and all N points are on the M intervals. Note: for any interval (a,b), 0 <= a <= b <= 10^18.
## Solution:
Do binary search on the value of D (0 <= D <= 10^18). For each value of D, we can check if we can place N points on M intervals where the min distance between any 2 points is D through a greedy strategy: place each point at the left most position position possible.
## Time complexity:
O(NlogN + (N+M)log(max_dist)) = O((N+M)log(max_dist)) where max_dist = 10^18.
# Problem 2:
## Problem formulation: 
Given M cereal boxes 1,2,...,M (1 <= M <= 10^5). Given N cows with preferences (f, s) with (1 <= N <= 10^5) and 1 <= f,s <= M. The order of those cows is kept as given in the input. The procedure: We go through the list of cows from left to right, a cow with preference (f,s) performs the following process when it is their turn:
    1. If f is still available, take f  
    2. If f is not available but s is, take s  
    3. Otherwise, do nothing  
