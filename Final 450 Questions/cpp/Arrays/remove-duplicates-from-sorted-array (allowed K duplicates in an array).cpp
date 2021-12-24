/* Question: Given an non-decreasing array of size n, we need to change the array such that for each element there should be at most K duplicates in the array.

Approach
We will use a variable say cnt to store the frequency of the element we are currently traversing and a start variable which will point to the index where next element can be inserted or it's basically the size of the updated array or desired array.

Post: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/discuss/1642499/Allow-K-times-or-Explanation-or-CPP
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = (int) nums.size();
        
        if(n <= 1) return n;
        
        int start = 1;
        int cnt = 1;
        int K = 2;				// desired duplicated allowed
        
        for(int i=1; i<n; i++) {
		     /* The below if-else is basically to find the frequency of the element only. */
            if(nums[i] == nums[i-1]) {
				// if the adjacent element is same, then increase the frequency
                cnt++;					
            } else {
		       // if we encounter a new element then update the frequency
                cnt = 1;
            }
            
            // Whenever the frequency is less than or equal to K then include in the array
            if(cnt <= K) {
                nums[start++] = nums[i];
            }
        }
        
        return start;
    }
};