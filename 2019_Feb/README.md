# Problem 1:
## Topics: Sliding window, Sorting
## Problem formulation:  
    Given N cows on a number line. At any point, we can make a move by picking a cow at an "endpoint" - the largest or smallest number  
    and move it to a number that is currently not occupied and not an endpoint.  
    Find the maximum and minimum number of moves before the cows become grouped in N
    of consecutive locations.  
## Solution:
    Soln: We need to solve 2 problems: min and max
    - For the min, we want to look for the N-length window containing the most cows
    (fewest empty spaces) because we can fill in the x empty spaces in the window
    with exactly x moves.
    - For the max, it is the difference between the biggest gap possible and the
    number of cows that are not already at the 2 end points
    => Formula: max(A[N-2] - A[0], A[N-1]-A[1]) - (N-2)
## Time complexity:
O(NlogN)
# Problem 2:
## Topics: Simulation, Recursion
## Problem formulation: 

## Solution:

# Problem 3:
# Topics: Graph, Sorting
## Problem formulation:

## Solution: 
   
