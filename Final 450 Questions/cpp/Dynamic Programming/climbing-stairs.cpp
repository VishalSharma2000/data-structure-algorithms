/* A person is standing at position 0, find all the distinct ways to reach the end of the straicase(n) */

/* Approach: At each level of straicase we have two choices to make, we can either go one step or take two steps, whenever we reach the end of the straicase we have reached our destination. */

/* Recusive + Memoization Approach */
/* Normal Recursive Approach: 
  TC: O(2^n) - because at each point we have two choices to make 
  SC: O(n) - call stack

  Memoization Approach:
  TC: O(N) - each step will be calculated only onces
  SC: O(N) - memoization array
*/
class Solution {
public:
    int memo[46];
    
    /* helper functions returns total ways to reach the destination n from the position i */
    int helper(int i, int n) {
        if(i > n) {
            return 0;
        }
        if(i == n) {
            // return 1 to add a new way to reach the destination
            return 1;
        }
        
        // if already calculated then return the value
        if(memo[i] != -1) return memo[i];
        
        return memo[i] = helper(i+1, n) + helper(i+2, n);
    }
    
    int climbStairs(int n) {
        int startingPoint = 0;
        memset(memo, -1, sizeof memo);
        
        return helper(startingPoint, n);
    }
};

/* Bottom Up Approach */