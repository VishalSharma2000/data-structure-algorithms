/* https://leetcode.com/problems/search-a-2d-matrix-ii/ */

class Solution {
public:
    // TC: O(n+m), SC: O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        
        int i = 0, j = m-1;
        while(i<n && j>=0) {
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] > target) {
                j--;
            } else {
                i++;
            }
        }
        
        return false;
    }
};