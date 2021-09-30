class Solution {
public:
    vector<int> sets;
    
    bool checkIfPossible(vector<int> &nums, int index, int neededSum) {
        if(index == nums.size()) {
            bool poss = true;
            for(int i=0; i<sets.size(); i++) {
                // cout << sets[i] << " ";
                if(sets[i] != neededSum) {
                    poss = false;
                    break;
                }
            }
            // cout << endl;
            return poss;
        }
        
        bool status = false;
        
        for(int i=0; i<sets.size(); i++) {
            if(sets[i] + nums[index] <= neededSum) {
                sets[i] += nums[index];
                status |= checkIfPossible(nums, index+1, neededSum);
                sets[i] -= nums[index];
            }
        }
        
        return status;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < k) return false;
        
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if(totalSum%k != 0) return false;
        
        int neededSum = totalSum / k;
        int maxElement = *max_element(nums.begin(), nums.end());
        if(maxElement > neededSum) return false;
        
        sets.resize(k, 0);
        sort(nums.rbegin(), nums.rend());
        return checkIfPossible(nums, 0, neededSum);
    }
};