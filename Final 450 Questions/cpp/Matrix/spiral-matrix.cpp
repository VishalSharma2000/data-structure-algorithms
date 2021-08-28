/* Given a 2d matrix we have to traverse the elements of the matrix in spiral order */

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