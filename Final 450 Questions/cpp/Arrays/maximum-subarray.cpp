/* Given an array consisting of positive and negative elements, return the maximum contigous sum */
/* If suppose array has all positive elements then maximum sum will be sum of all elements
or if array has all negative elements then maximum sum will be the least number of the array 
or if array has mixed numbers then kadane's algorithm is used here */

/* It's basically a DP problem where we have to find the maximum sum subarray. 
State of subproblem dp[i] => maximum sum till index i */
class Solution {
public:
  int maxSum(vector<int> &nums) {
    int n = nums.size();
    int dp[n];

    dp[0] = nums[0];
    int maxSum = dp[0];

    for(int i=1; i<n; i++) {
      // if the sum till i-1 is positive then adding current element 
      dp[i] = nums[i] + (dp[i-1] > 0 ? dp[i-1] : 0);
      maxSum = max(maxSum, dp[i]);
    }

    return dp[n-1];
  }
}

/* Since our subproblem depends only on the previous state, there is no need to keep track of all the sums. */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        
        int maxSum = INT_MIN;
        int currSum = 0;
        
        for(int i=0; i<n; i++) {
            currSum += nums[i];
            
            maxSum = max(maxSum, currSum);
            
            if(currSum < 0) {
                currSum = 0;
            }
        }
        
        return maxSum;
    }
};

/* If we want to print the subarray with maximum sum */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        
        int maxSum = INT_MIN;
        int currSum = 0;
        int start = 0, end = 0, s = 0;
        
        for(int i=0; i<n; i++) {
            currSum += nums[i];
            
            if(currSum > maxSum) {
              start = s;
              end = i;
            }
            
            if(currSum < 0) {
                currSum = 0;
                s = i+1;
            }
        }
        
        for(int i=start; i<=end; i++) {
          cout << nums[i] << " ";
        }

        return maxSum;
    }
};