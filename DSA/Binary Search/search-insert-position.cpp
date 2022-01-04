/* 
  Leetcode Question: https://leetcode.com/problems/search-insert-position/
*/

/* If you look nicely, basically we have to find the first position say p in the array such that for all i [p, n-1] the value is >= target.
We can make use of lower_bound algorithm builtin function, it returs the first index which is more than or equal to the target element */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0, end = n; /* Note that end is not n-1, it is n (to handle case when the target element need to be added at end) */
        
        while(start < end) {
            int mid = start + (end - start)/2;
            
            /* We have to find the first position(say p) in the array or search space such that for all i from (p, n-1) is >= target */
            if(nums[mid] >= target) end = mid;
            else start = mid+1;
        }
        
        return end;
    }
};