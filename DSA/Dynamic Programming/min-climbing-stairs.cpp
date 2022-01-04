/* Two things to notice - we have one array and the question is asking minimum cost i.e. optimizing...
  So, question can be solved using dp..

  Another way of approaching...
  we have to find mimimum i.e. optimized solution and
  at every step or at every element of array we had a choice to make i.e. either one step or two step...
  the above two statement is enough to say that the solution can be solved using dp. 
 */

/* Since we are taking n+1 as the top level, so to get (n+1)th index we have to make the array of size (n+2) */
const int SIZE = 1002;
class Solution {
public:
    
    int dp[SIZE];
    
    int solve(vector<int> &cost, int i, int n) {
        if(i >= n+1) return 0;
        if(dp[i] != -1) return dp[i];
        int currCost = i == 0 ? 0 : cost[i-1];
        
        return dp[i] = currCost + min(solve(cost, i+1, n), solve(cost, i+2, n));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));
        dp[cost.size()+1] = 0;
        return solve(cost, 0, cost.size());
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev2 = 0, prev1 = 0;
        int n = cost.size();
        
        if(n < 2) return 0;
        
        for(int i=3; i<=n+1; i++) {
            int temp = min(prev1 + cost[i-2], prev2 + cost[i-3]);
            
            prev2 = prev1;
            prev1 = temp;
        }
        
        return prev1;
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // cost.insert(cost.begin(), 0);
        int n = cost.size();
        
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 0;
        
        for(int i=2; i<n+1; i++) {
            dp[i] = min(cost[i-1] + dp[i-1], cost[i-2] + dp[i-2]);
        }
        
        return dp[n];
    }
};