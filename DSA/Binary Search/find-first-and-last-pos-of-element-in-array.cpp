/* 
  Leetcode Question: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans{-1, -1};
        
        if(n == 0) return ans;
        int low = 0, high = n-1;
        
        // find the first occurance of the number
        int res = -1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            
            if(nums[mid] == target) {
              // still continue the search on left side to check if target occurs
                res = mid;
                high = mid-1;
            } else if(nums[mid] > target) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        
        ans[0] = res;
        
        // find the last occurance of the target
        res = -1;
        low = 0, high = n-1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            
            if(nums[mid] == target) {
              // still continue the search on right side to check if target occurs
                res = mid;
                low = mid+1;
            } else if(nums[mid] > target) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        ans[1] = res;
        
        return ans;
    }
};