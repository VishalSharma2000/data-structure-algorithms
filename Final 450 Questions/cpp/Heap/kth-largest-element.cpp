/*
  LeetCode Question - 215
  https://leetcode.com/problems/kth-largest-element-in-an-array/
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /* Declare Min Heap */
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        /* Make a min heap and push the elements until the size is less than k, after that
           if the newer element is less than minHeap top then they will can't be part of the final answer 
           if the newer element is more than minHeap top they can be part of the solution */
        for(int i=0; i<nums.size(); i++) {
            minHeap.push(nums[i]);
            if(minHeap.size() > k) 
                minHeap.pop();
        }
        
        return minHeap.top();
    }
};