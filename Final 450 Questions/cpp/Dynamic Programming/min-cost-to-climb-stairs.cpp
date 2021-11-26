/* Leetcode Question: https://leetcode.com/problems/min-cost-climbing-stairs/ */

/* We are given an array of cost which gives the cost of going to ith stair. We can either start from 0th stair or 1st stair and we have to find the minimum cost to reach the top of the floor which is (n+1)th stair */

/* In the below approach the flow of the code is - If I'm at ith position then I can go to (i+1)th and (i+2)nd position */
class Solution {
public:
    int memo[1002];
    
    /* Returns the min cost to reach the end position from the ith position */
    int getCost(int i, int end, vector<int> &cost) {
        int n = cost.size();
        
        if(i >= end) return 0; // already reached the end position then cost will be zero
        if(memo[i] != -1) return memo[i];
        
        int currCost = i >= 1 ? cost[i-1] : 0; // if present on any stairs then consider cost of the stair (basically to avoid the 0 index condition)
        
        // we can jump either one step or two step from the ith position
        return memo[i] = currCost +
                min(getCost(i+1, end, cost), getCost(i+2, end, cost));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(memo, -1, sizeof memo);
        
        return min(getCost(0, n+1, cost), getCost(1, n+1, cost));
    }
};

/* In the below approach, it is the opposite of the above, if I'm at ith position then I would have came from (i-1) position or (i-2) position */
/* We are using only two variables, because our dp state or recurrance relation only depends on the previous two costs. Note that we have to go to n+1 position not the nth position */
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev1 = 0, prev2 = 0;
        int n = cost.size();
        
        if(n < 2) return 0;
        
        int costAtI;
        for(int i=3; i<=n+1; i++) {
            costAtI = min(cost[i-3] + prev2, cost[i-2] + prev1);
            
            prev2 = prev1;
            prev1 = costAtI;
        }
        
        return costAtI;
    }
};