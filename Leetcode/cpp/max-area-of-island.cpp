/* Given a grid of size m*n, where each cell of the grid can either be 1 or 0. 1 Indicates that it is an island otherwise it's a water.
So, we have to find the area of biggest island. We can travel in all four directions.

Approach: 
A simple approach is to traverse the 2d grid matrix and whenever we encounter a 1 then we can go for dfs from that cell.
After visiting a particular cell we will convert the value 1 into value 0 so that we don't call dfs function again for 
this cell.

Time Complexity: O(m * n)
Space Complexity: If visited array is used then O(m*n) else O(1)
*/
class Solution {
public:
    int dfs(vector<vector<int>> &grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        /* Out of bound condition or when 0 is encountered */
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return 0;
        grid[i][j] = 0;

        /* Current cell + area of all four directions */
        return 1 + dfs(grid, i-1, j) + dfs(grid, i+1, j) + dfs(grid, i, j-1) + dfs(grid, i, j+1);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();

        int maxArea = 0;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(grid[i][j])
                    maxArea = max(dfs(grid, i, j), maxArea);
            }
        }

        return maxArea;    
    }
};