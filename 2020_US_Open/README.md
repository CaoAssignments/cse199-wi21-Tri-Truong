# Problem 1:
## Problem formulation:  
Given N points (2 <= N <= 10^5) and M intervals (1 <= M <= 10^5). Return the maximum value of D where D is the distance between 2 closest points and all N points are on the M intervals. Note: for any interval (a,b), 0 <= a <= b <= 10^18.
## Solution:
Do binary search on the value of D (0 <= D <= 10^18)
