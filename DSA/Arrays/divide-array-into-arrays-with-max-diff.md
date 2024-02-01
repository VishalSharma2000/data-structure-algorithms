# Intuition
As the question says that we want to divide the array in size of 3 such that the difference between any two elements is less than equal to k so now the question has reduced to find the group of numbers with minimum difference.

Since k is positive number, the minimum difference we can get is 0 (subtracting two equal numbers)

To minimize the difference we need to choose the numbers which are close to each other and to get this we can sort the array in ascending or descending order.

For example:

arr = [1 4 5 2 3 6] and k = 5
Now we can take [1, 2, 3] or [1, 4, 6] anything because it will satisfy k. Now if two extreme numbers are satisfying the condition of k then adjacent numbers in sorted will also satisfy. That is the reason sorted array will always give right solution.

# Approach
Approach is simple, we need to sort the array in ascending or descending order.

Since the question has already specified that the size of the array is a multiple of 3, we need not worry about out of index accessing in array.

We can take a variable i for traversal, and check the difference between arr[i+2] - arr[i]. If it is less than k then our condition is satisfies (arr[i+1]-arr[i] and arr[i+2]-arr[i] will be definately less) otherwise we can return empty list.

# Complexity
Time complexity: O(n * log(n))
log(n) => is for sorting the array. Internally it will use merge sort for sorting the array in c++
Space complexity: O(n^2)
Actually this is not the extra space we are using, we are making this 2d array to return to the caller function

# Code
```
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int i = 0;
        while(i < n) {
            if(nums[i+2] - nums[i] > k)
                return {};
            else {
                ans.push_back({ nums[i], nums[i+1], nums[i+2] });
                i += 3;
            }
        }

        return ans;
    }
};
```