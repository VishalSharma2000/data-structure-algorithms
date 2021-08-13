/* Using STL */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        
        int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(first == n || nums[first] != target) return {-1, -1};
        ans.push_back(first);
        
        int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        ans.push_back(last-1);
        
        return ans;
    }
};

/* Using Manual Binary Search */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans{-1, -1};
        
        if(n == 0) return ans;
        int low = 0, high = n-1;
        
        while(low < high) {
            int mid = (low + high) / 2;
            
            if(nums[mid] < target)
                low = mid+1;
            else 
                high = mid;
        }
        
        if(nums[low] != target) return ans;
        ans[0] = low;
        
        high = n-1;
        while(low < high) {
            int mid = (low + high + 1) / 2;
            
            if(nums[mid] <= target)
                low = mid;
            else 
                high = mid-1;
        }
        ans[1] = low;
        return ans; 
    }
};