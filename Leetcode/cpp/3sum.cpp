/* LeetCode Question: https://leetcode.com/problems/3sum/ */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        if(n < 3) return {};
        sort(nums.begin(), nums.end());
        
        /* Here we want the nos whose sum is equal to zero. Since, taking the first number as negative so the addition of next two nos 
        if equal to first number would be 0 */
        for(int i=0; i<n; i++) {
            int target = -nums[i];
            
            /* Two Pointer Approach */
            int start = i+1;
            int end = n-1;
            
            while(start < end) {
                int sum = nums[start] + nums[end];
                
                if(sum == target) {
                    vector<int> triplets{nums[i], nums[start], nums[end]};
                    ans.push_back(triplets);
                    
                    /* If same number is present then it would create same choosing of elements to get the sum equal 0, hence 
                    remove those duplicates */
                    while(start < end && nums[start] == triplets[1])
                        start++;
                    
                    /* Removing the duplicates */
                    while(start < end && nums[end] == triplets[2])
                        end--;
                    
                } else if(sum < target) {
                    start++;
                } else {
                    end--;
                }
            }
            
            while(i+1 < n && nums[i+1] == nums[i])
                i++;
        }
        
        return ans;
    }
};