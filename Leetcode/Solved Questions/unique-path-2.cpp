/*
  Problem Statement: https://leetcode.com/problems/unique-paths-ii/
  A robot has to go from (0, 0) to (m-1, n-1) and there are some obstacles in between the grids, so we have to find the maximum number of paths to reach (m-1, n-1)
*/

/* First Approach Solution */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        int m = ob.size();
        int n = ob[0].size();
        
        /* If the start of end point contain obstacle then the max unique path will be zero */
        if(ob[0][0] == 1 || ob[m-1][n-1] == 1) return 0;
        
        int dp[m][n];
        
        /* If the position contain obstacle then initialize with -1 */
        for(int i=0; i<m; i++) 
            for(int j=0; j<n; j++) 
                dp[i][j] = ob[i][j] ? -1 : 0;
        
        /* DP Initialization Step 
          we can reach the current row cell and current column cell until we have not encountered any obstacle
         */
        for(int i=0; i<m; i++) {
            if(dp[i][0] == -1) break;
            dp[i][0] = 1;            
        }
        
        for(int j=0; j<n; j++) {
            if(dp[0][j] == -1) break;
            dp[0][j] = 1;
        }
        
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(dp[i][j] == -1) continue;
                int up = dp[i-1][j] == -1 ? 0 : dp[i-1][j];
                int down = dp[i][j-1] == -1 ? 0 : dp[i][j-1];
                
                dp[i][j] = up + down;
            }
        }
        
        return dp[m-1][n-1];
    }
};

/* Learned Solution - DP */
class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        
        vector<vector<int> > dp(m + 1, vector<int> (n + 1, 0));
        
        /* To avoid if condition for -ve i and j inside for loop */
        dp[0][1] = 1;

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                /* Since, we have initialized the dp table with 0 values we don't have to worry about the case where
                if we want to find the max path from (i,j) and any of its adjacent side contains obstacle */
                if (!obstacleGrid[i - 1][j - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m][n];
    }
};