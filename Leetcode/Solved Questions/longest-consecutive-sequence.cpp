class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return n;
        
        /* All the operations on unordered_set take time complexity of O(1) */
        unordered_set<int> ans;
        for(int i=0; i<n; i++) ans.insert(nums[i]);
        /* Inserting all the nos into the unordered_set will take O(n) time  */        
        
        int len = 0;
        for(int i=0; i<n; i++) {
            /* If the nums[i]-1 is present then continue because
            we don't know the start of the sequence....
            we will count the sequence length from the smallest number, hence we are first finding the smallest number of the sequence */
            if(ans.find(nums[i]-1) == ans.end()) {
                /* Now we have the smallest, hence we can apply loop to find the length of hte sequence */
                int j = nums[i];    
                
                while(ans.find(j) != ans.end()) j++;
                
                len = max(len, j-nums[i]);
            }
        }
        
        return len;
    }
};