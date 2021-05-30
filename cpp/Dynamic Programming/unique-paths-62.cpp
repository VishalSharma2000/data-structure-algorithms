unsigned long dp[101][101];

/* Recursive + memoization approach to solve the question. 
  But this solution will give TLE for bigger test cases on leetcode. 
  
  Approach:
    We are finding all the unique paths to (i, j) from the starting position (0, 0) for all the intermediate parts and with the help of that
    finding the total number of unique paths to (m-1, n-1) from (0, 0)
*/
unsigned long solve(int i, int j) {
    if(i == 0 && j == 0) return 1;
    if(i < 0 || j < 0) return 0;

    return dp[i][j] = solve(i-1, j) + solve(i, j-1);
}

void solveRecursive(int m, int n) {
  memset(dp, -1, sizeof(dp));
  
  return solve(m-1, n-1);
}

int uniquePaths(int m, int n) {
    int dp[m][n];

    /* 
      Point to keep in mind everytime is - we don't have to find shortest path from (i, j) to (0, 0)
      Since we are restricted to only make move in right and down side of the grid - total number of unique paths to reach 
      (0, 0) from (0, j) for all 0 <= j <= n-1 and (0, 0) from (i, 0) for all 0 <= i <- m-1 will be one 
    */
  
    /* Initialization */ 
    for(int i=0; i<m; i++) dp[i][0] = 1;
    for(int i=0; i<n; i++) dp[0][i] = 1;

    /* From (i, j) I can either come from (i-1, j) or (i, j-1). Hence adding the number of paths to reach (i, j) from the other two paths */
    for(int i=1; i<m; i++) {
        for(int j=1; j<n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[m-1][n-1];
}
