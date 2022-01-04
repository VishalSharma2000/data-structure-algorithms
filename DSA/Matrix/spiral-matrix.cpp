/* Given a 2d matrix we have to traverse the elements of the matrix in spiral order */
/* When revising try the recursive approach on your own - https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/ */

/* We are basically printing the corner values of the matrix in clockwise direction, so in have 4 directions */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int R = matrix.size(), C = matrix[0].size();
        vector<vector<bool>> seen(R, vector<bool>(C, false)); // to track which cell is visited
        vector<int> ans;
        
        if(R == 0) return ans;
        
        int dir[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // four direction
        int r = 0, c = 0, di = 0;
        for(int i=0; i<R*C; i++) {
            ans.push_back(matrix[r][c]);
            seen[r][c] = true;
            
            int nr = r + dir[di][0];
            int nc = c + dir[di][1];
            
            /*Whenever reach a boundary of the matrix or encounter a cell which was previously visited then change the direction and reset the next row and column*/
            if(nr < 0 || nr == R || nc < 0 || nc == C || seen[nr][nc]) {
                di = (di + 1)%4;
                nr = r + dir[di][0];
                nc = c + dir[di][1];
            }
            
            r = nr;
            c = nc;
        }
        
        return ans;
    }
};

/* Similar approach as above just we are using for loop */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int R = matrix.size(), C = matrix[0].size();
        vector<int> ans;
        
        if(R == 0) return ans;
        
        int directionNo = 0;
        /* The below are basically the boundary lines on which the values need to be printed */
        int top = 0, down = R-1, left = 0, right = C-1;
        while(top <= down && left <= right) {
            if(directionNo == 0) {
                for(int i=left; i<=right; i++) 
                    ans.push_back(matrix[top][i]);
                
                top++;
            } else if(directionNo == 1) {
                for(int i=top; i<=down; i++) 
                    ans.push_back(matrix[i][right]);
                
                right--;
            } else if(directionNo == 2) {
                for(int i=right; i>=left; i--) {
                    ans.push_back(matrix[down][i]);
                }
                
                down--;
            } else if(directionNo == 3) {
                for(int i=down; i>=top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                
                left++;
            }
            
            directionNo = (directionNo + 1)%4;
        }
        return ans;
    }
};

/* Basically, the approach is to used 4 pointers or 4 variables to show the terminating rows and columns */
/* left => left column boundary, right => right column boundary, top => top row boundary, down => down row boundary */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        int left = 0, right = col-1, up = 0, down = row-1;
        vector<int> ans;
        
        while(ans.size() < row * col) {
            // from left to right
            for(int i=left; i<=right; i++)
                ans.push_back(matrix[up][i]);
            
            // from right to left
            for(int i=up+1; i<=down; i++) 
                ans.push_back(matrix[i][right]);
            
            // while traversing again from right to left, first check that we should be on different rows
            if(up != down) {
                for(int i=right-1; i>=left; i--) 
                    ans.push_back(matrix[down][i]);
            }
            
            // while traversing again from bottom to up, check that we are on two different columns
            if(left != right) {
                for(int i=down-1; i>up; i--)
                    ans.push_back(matrix[i][left]);
            }
            
            // update the boundaries
            left++;
            up++;
            right--;
            down--;
        }
        
        return ans;
    }
};
