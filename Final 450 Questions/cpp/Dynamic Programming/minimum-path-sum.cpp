/* https://leetcode.com/problems/minimum-path-sum/ */
/* Approach: First of all note that always try to make the recursive function in the form of sub problems, i.e. whatever problem is defined in the problem statement try to make the recursive function in the same format. So, here we had to reach n-1, m-1 position so instead of starting from 0, 0 to reach the bottom right corner of the grid, we started from bottom right corner of the grid and solved all the sub problems from where we can come to the n-1, m-1 position */

/* Recursive + Memoization Approach */
/* Recusive: TC: O(2^(n*m)) because we can reach each cell by two ways */
/* Memoization: TC: O(n*m) because we can traversing each cell only once and we are using the already calculated values */
class Solution {
public:
    int memo[201][201];
    
    int helper(int i, int j, vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        
        if(i < 0 || i == m || j < 0 || j == n) return 1000000;
        if(i == 0 && j == 0) return grid[i][j];
        
        if(memo[i][j] != -1) return memo[i][j];
        
        return memo[i][j] = grid[i][j] + min(helper(i-1, j, grid), helper(i, j-1, grid));
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        memset(memo, -1, sizeof memo);
        
        return helper(m-1, n-1, grid);
    }
};

/* Bottom Up Approach */
/* TC: O(n*m) */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        int dp[n][m];
        
        // initialization
        dp[0][0] = grid[0][0];
        for(int i=1; i<m; i++) 
            dp[0][i] = grid[0][i] + dp[0][i-1]; 
        for(int j=1; j<n; j++) 
            dp[j][0] = grid[j][0] + dp[j-1][0];
        
        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n-1][m-1];
    }
};

/* From the the dp state it is clear that it depends on the previous row and previous column only so it's not necessary to maintain complete n*m matrix */
