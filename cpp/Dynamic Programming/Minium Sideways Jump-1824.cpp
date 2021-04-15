/*
  Time complexity: O(n)
  Space Complexity: O(n)
*/

class Solution {
public:
    int minSideJumps(vector<int>& arr) {
        int n = arr.size();
        int dp[3][n];
        
        // initialization
        dp[1][0] = 0; // since no jump is needed
        dp[0][0] = dp[2][0] = 1; // since one jump is needed to reach here
        
        for(int i=1; i<n; i++) {
            for(int r=0; r<3; r++) {
                /* If the current position has obstacle or the previos position had obstacle in the lane r+1, then
                   the jumps required to reach her will be inf 
                   
                   Obstacle at previous position also matters bcoz...notice that we are filling the current position say i, with the 
                   previous position say i-1, so if there is obstacle in lane r+1(0  based indexing) at position i-1 then I won't be able to reach [r+1][i-1].
                   and the only way to reach [r+1][i] is throught [r+1][i-1]
                */
                if(arr[i] == r+1 || arr[i-1] == r+1)
                    dp[r][i] = n;
                else
                    dp[r][i] = min(dp[r][i-1], min(dp[(r+1)%3][i-1], dp[(r+2)%3][i-1]) + 1);
              
              /* One jump will be required to come form another lane */
            }
        }
        
        return min(dp[0][n-1], min(dp[1][n-1], dp[2][n-1]));
    }
};
