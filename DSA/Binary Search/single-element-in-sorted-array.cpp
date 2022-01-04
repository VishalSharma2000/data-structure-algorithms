/* LeetCode Question: https://leetcode.com/problems/single-element-in-a-sorted-array/ */
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        int start = 0, end = n-1;
        while(start < end) {
            int mid = start + (end-start)/2;
            
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];
            
            if(nums[mid] == nums[mid+1]) {
                int ls = abs(mid - start);
                if(ls%2) end = mid - 1;
                else start = mid + 2;
            }  
            
            else if (nums[mid] == nums[mid-1]) {
                int rs = abs(end - mid);
                
                if(rs%2) start = mid + 1;
                else end = mid - 2;
            }
        }
        
        return nums[start];
    }
};