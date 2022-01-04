/* Given a 2d array where each cell represent the gold in tone. A miner is standing any any row of 1st column. Find the maximum amount of gold miner can collect */

/* Approach: It's like a normal source to destination problem pattern problem. Only one point to note that we don't have to find the maximum gold collected at the end of the row and column, we have to find the maximum gold collected at any point but since all the amount of gold at each cell is position the maximum amount will be amoung the last column */

/* Recursive + Momoization Approach */
/* Recursive: O(3^(m*n)) because each cell can be reached from 3 points */
/* Memoization: O(n*m) because we will traverse the complete 2d array only once */
class Solution{
private:
    int memo[51][51];
public:
    int helper(vector<vector<int>> &M, int i, int j) {
        int n = M.size(), m = M[0].size();
        
        if(i < 0 || i == n || j < 0 || j == m) return 0;
        
        if(memo[i][j] != -1) return memo[i][j];
        
        int p1 = helper(M, i-1, j+1);
        int p2 = helper(M, i, j+1);
        int p3 = helper(M, i+1, j+1);
        
        memo[i][j] = M[i][j] + max({ p1, p2, p3 });
        
        return memo[i][j];
    }

    int maxGold(int n, int m, vector<vector<int>> M)
    {
        memset(memo, -1, sizeof memo);
        
        int maxProfit = INT_MIN;
        for(int i=0; i<n; i++) {
            maxProfit = max(maxProfit, helper(M, i, 0));   
        }
        
        return maxProfit;
    }
};

/* Bottom up approach */
class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M) {
        int dp[n][m];
        int maxGold = INT_MIN;
        
        /*
            dp[i][j] => from (i, j) to end how much gold i can collect
            dp[i][j] => till (i, j) how much gold i can collect => this defination is used
        */
        
        for(int i=0; i<n; i++) {
            dp[i][0] = M[i][0];
            maxGold = max(maxGold, dp[i][0]);
        }
            
        for(int j=1; j<m; j++) {
            for(int i=0; i<n; i++) {
                int p1 = i-1 >= 0 ? dp[i-1][j-1] : 0;
                int p2 = i+1 < n ? dp[i+1][j-1] : 0;
                int p3 = dp[i][j-1];
                
                dp[i][j] = M[i][j] + max({ p1, p2, p3 });
                maxGold = max(maxGold, dp[i][j]);
            }
        }

        return maxGold;
    }
};