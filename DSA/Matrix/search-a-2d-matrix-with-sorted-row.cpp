/* Leetcode Question: https://leetcode.com/problems/search-a-2d-matrix/ */

/* Here the first element of each row is greater than the last element of previous row. So, basically we can see the complete 2d array as one sorted array and apply binary search */

class Solution {
public:
    // TC: O(log(n*m)) => O(logn + logm)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        
        // search space end points
        int start = 0, end = n*m - 1;
        
        while(start <= end) {
            int mid = start + (end - start) / 2;
            
            int ri = mid/m; // row index
            int ci = mid%m; // column index
            
            if(matrix[ri][ci] == target) return true;
            else if(target < matrix[ri][ci]) end = mid - 1;
            else start = mid + 1;
        }
        
        return false;
    }
};