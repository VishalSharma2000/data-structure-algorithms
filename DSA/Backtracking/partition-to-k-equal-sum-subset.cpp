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
        
        // we have k choices each time
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

/* Another approach: Here we are actually making only one set at a time rather than considering all k sets(which we did in the above approach). So, idea is to make one set at a time with neededSum (totalSum / K). Once we obtain this sum we decrease the neededParitionSize(which is k) by one. So, at last when we need only one partition with sum neededSum then we can say that the array can be divided into k subsets with equal sum.

Now the problem reduces to finding a subset with sum k, so for each element we have a choice to make, either to take that element or to skip that element in the current set. 

After getting one set we will again start subset set problem from 0 index and only take decision for those nos which were not considered in last set. So, to keep track of which element is being already choosen or which is still left we are using a visited array. 

Now, in the current question all the array elements are positive hence our target sum (totalSum / k) will always be more than 0 but in cases with negative elements are present in array we can get target = 0 so in that case we need to atleast have one element in our set (because currSum is intialized to zero so if we don't track the subset size then we will consider empty set too)*/
class Solution {
public:
    bool checkIfPossible(vector<int> nums, int startIndex, vector<bool>&visited, int currSum, int currSetSize, int neededSum, int k) {
        int n = nums.size();
        if(k == 1) return true;
        if(currSum > neededSum) return false;
        if(currSum == neededSum && currSetSize > 0) 
            return checkIfPossible(nums, 0, visited, 0, 0, neededSum, k-1);
        
        for(int i=startIndex; i<n; i++) {
            if(!visited[i] && currSum + nums[i] <= neededSum) {
                currSum += nums[i];
                visited[i] = 1;
                if(checkIfPossible(nums, i+1, visited, currSum, currSetSize+1, neededSum, k)) return true;
                visited[i] = 0;
                currSum -= nums[i];
            }
        }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < k) return false;
        
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if(totalSum%k != 0) return false;
        
        int neededSum = totalSum / k;
        int maxElement = *max_element(nums.begin(), nums.end());
        if(maxElement > neededSum) return false;
        
        vector<bool> visited(n, false);
        return checkIfPossible(nums, 0, visited, 0, 0, neededSum, k);
    }
};