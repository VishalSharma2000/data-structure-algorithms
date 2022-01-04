/* A robot is standing at position (0, 0) on a grid of size (m, n). So, we have to find the number of unique paths to reach the target (m, n) */
/* Keep in mind that here we don't have to find the min cost path to reach the destination, we just have to find different paths which will take the robot to the target cell
So, this question can be solved in 2 ways
1) We can start the recursive function from (m-1, n-1) {doing 0 based indexing}
2) We can start the recursive function from (0, 0)

1) In this case the base condition to terminate the recursive function would be to reach (0, 0)...So, we would move in all allowed directions(here top and right) and at each step we will check if we have reached the starting position. If yes then we can return 1 to indicate the success, and if at any point we go out of boundary of the grid then we can return 0 indicating unsucess.
2) Similarly, here we are starting from (0, 0) and going in all possible direction and if we reach the target cell then we can return 1 other wise 0 */

/* Recursive Approach */
/* Time Complexity => branches * depth => 2 ^ (m+n) */
class Solution {
  public:
    int uniquePathsRecursive(int m, int n) {
      if(m < 0 || n < 0) return 0;
      if(m == 0 && n == 0) return 1;

      /* Note that here I have started from (m, n) and finding the starting cell (0, 0), and the boundary of the cell would break at -1 or -1 only 
        For the other case the base condition would change
      */

      return uniquePathsRecursive(m-1, n) + uniquePathsRecursive(m, n-1);
    }

    int uniquePaths(int m, int n) {
      return uniquePathsRecursive(m - 1, n - 1);
    }
};

/* Memoization Approach */
/* Time Complexity: O(m * n) => bcoz each cell will be visited once, for already visited nodes the dp will help us to directly return the calculated value
Space Complexity: O(m * n) => dp table to store the values for future use */
class Solution {
  public:
    /* Here the changing variables are m and n, hence the dimension of the dp table will be m x n */
    int dp[m][n];

    int uniquePathsMemoization(int m, int n) {
      if(m < 0 || n < 0) return 0;
      if(m == 0 && n == 0) return dp[m][n] = 1;

      /* If we already know the number of unique paths from (m, n) then directly return the answer */
      if(dp[m][n] != -1) return dp[m][n];

      /* Note that here I have started from (m, n) and finding the starting cell (0, 0), and the boundary of the cell would break at -1 or -1 only 
        For the other case the base condition would change
      */

      return dp[m][n] = uniquePathsRecursive(m-1, n) + uniquePathsRecursive(m, n-1);
    }

    int uniquePaths(int m, int n) {
      memset(dp, -1, sizeof(dp));
      return uniquePathsRecursive(m - 1, n - 1);
    }
};

/* Bottom-Up Approach
  Time Complexity : O (m * n)
  Space Complexity: O (m * n) */
class Solution {
  public:
      int uniquePaths(int m, int n) {
        int dp[m][n];
          
          /* Initialization - all the cells in the same row and same column will only have 1 unique path to reach the target cell
          - the above stmt is true only for this question bcoz of the traversing restriction */ 
        for(int i=0; i<m; i++) dp[i][0] = 1;
        for(int i=0; i<n; i++) dp[0][i] = 1;
        
        /* Calcalate the distance for each cell - Here each cell represent the maximum number of unique paths to reach from that cell to the target cell
        so dp[i][j] = max no. of unique paths from (i, j) to (m, n) */
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
};