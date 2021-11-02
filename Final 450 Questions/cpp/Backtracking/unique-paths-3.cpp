/* 
Leetcode Question: https://leetcode.com/problems/unique-paths-iii/ 

Approach: We have to find the count of all the paths from the starting cell(with value 1) to the destination cell(with value 2)
The main difference here is we have to visit all the empty cells also, so we don't have to just reach the destination cell we should also travel through all the empty cells (with value 0) and then that the last cell in the path should be the destination cell.

So, to keep track wheather all the empty cells are being visited or not first find all the number of valid cells (empty cells + destination cell) which we can visit. 
In the same nested for loop we can also find the starting point in the grid and store in x and y variable. 

Next, we can just traverse from starting point to all the 4 directions to explore all the paths and when we reach the destination cell we check for the condition that all the empty cells are being visited

and since we want to find all the paths, so when we are done with exploring all directions of a particular cell then we backtrack (by making it unvisited) so that we can explore other paths.

Note: we are making a cell visited by changing it's value to 3 but we can also change it to -1. It's more better way to do but just to show the signifance of visited array in place we are using value 3.
*/
class Solution {
public:
    int getPaths(vector<vector<int>> &grid, int i, int j, int validCells) {
        int n = grid.size(), m = grid[0].size();

        // breaking and block cell condition
        if(i < 0 || i == n || j < 0 || j == m || grid[i][j] == -1) return 0;
        
        // if already visited
        if(grid[i][j] == 3) return 0;
        
        // path completion condition
        if(grid[i][j] == 2) {
            return validCells == 0;
        }
        
        grid[i][j] = 3; // marking cell as visited
        
        // explore all paths
        int ans = 
            getPaths(grid, i-1, j, validCells-1) +
            getPaths(grid, i+1, j, validCells-1) + 
            getPaths(grid, i, j-1, validCells-1) +
            getPaths(grid, i, j+1, validCells-1);
        
        grid[i][j] = 0; // backtrack to explore other paths as well
        
        return ans;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        int x, y;
        int validCells = 0; // empty cells + distination cells
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 0 || grid[i][j] == 2) 
                    validCells++;
                else if(grid[i][j] == 1) 
                    x = i, y = j;
            }
        }
        
        return getPaths(grid, x, y, validCells);
    }
};