class Solution {
public:
    void findAllPermutations(vector<int> &nums, int l, int h, vector<vector<int> > &ans) {
        if(l == h) 
            ans.push_back(nums);
        else {
            for(int i=l; i<=h; i++) {
                swap(nums[l], nums[i]);
                
                findAllPermutations(nums, l+1, h, ans);
                
                swap(nums[l], nums[i]);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int> > ans;
        if(n == 0) return ans;
        findAllPermutations(nums, 0, n-1, ans);
        
        return ans;
    }
};
