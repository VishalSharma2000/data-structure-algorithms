/* Leetcode Question: https://leetcode.com/problems/4sum/ */

/* TC: O(n^(k-1)), SC: O(n) */
class Solution {
public:
    vector<vector<int>> twoSum(vector<int> &nums, int start, int target) {
        int n = nums.size();
        int low = start, high = n-1;
        
        vector<vector<int>> res;
        while(low < high) {
            int sum = nums[low] + nums[high];
            
            /* If sum is less than target or curr element is same as previous element then 
            increment start to get greater values or to avoid duplicate quadruplets */
            if(sum < target || (low > start && nums[low-1] == nums[low])) low++;
            /* If sum i  greater than target or curr element is same as next element then
            decrement end to get lesser values or to avoid duplicate quadruplets */
            else if(sum > target || (high+1 < n && nums[high+1] == nums[high])) high--;
            else res.push_back({nums[low++], nums[high--]});

            /* If we have duplicate pairs which sum to target, then those duplicates will also be avoided with the 2nd 
            condition of sum<target and sum>target if conditions */
        }
        
        return res;
    }

    /* Another Way to implement two sum logic - using hash set */
    /*
    vector<vector<int>> twoSum(vector<int> &nums, int start, int target) {
        unordered_set<int> s;
        vector<vector<int>> res;
        
        for(int i=start; i<nums.size(); i++) {
            if(res.empty() || (res.back()[1] != nums[i])) {
                if(s.find(target - nums[i]) != s.end())
                    res.push_back({ target-nums[i], nums[i] });
                
                s.insert(nums[i]);
            }
        }
        
        return res;
    }
    */

    vector<vector<int>> kSum(vector<int> &nums, int k, int start, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        
        /* If we have reached the end of the array or
        the sum of smallest number k times is greater than required target or
        the sum of largest number k times is lesser than required target then 
        there would be no elements to get the target sum */
        if(start == n || (k * (long) nums[start]) > target || (long) (k * (long) nums.back()) < target)
            return res;
        
        if(k == 2)
            return twoSum(nums, start, target);
        
        for(int i=start; i<n; i++) {
            /* i == start is added in if condition to prevent out of bound exception
            for i = 0, for i = 0 with the current condition the first conditino would
            become true hence nums[i-1] will not be evaluated */
            if(i == start || nums[i-1] != nums[i])
                for(vector<int> ele : kSum(nums, k-1, i+1, target - nums[i])) {
                    /* We are comparing curr element with previous element to avoid
                    the duplicate cases */
                    /* Iterating over all the elements with sum target-nums[i] */
                    res.push_back({nums[i]});
                    res.back().insert(res.back().end(), ele.begin(), ele.end());
                }
        }
        
        return res;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return kSum(nums, 4, 0, target);
    }
};