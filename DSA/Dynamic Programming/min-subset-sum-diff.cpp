/* Problem Stmt: Given an array of interger we have to find the minimum difference between two subset of the array */

/* Approach: 
It is clear that we have to find two subset such that their sum is minimized, so definitely question is bases on KP. But since we don't have any highest value (weight) given to us, so 
we will have to first figure out what will be the value or range of sum value. So, it can be seen that the range for sum will be from 0 to totalArrSum.

i.e.
set1 sum = 0
set2 sum (consisting of all elements) = array_sum
The above is one solution but is not mizimised

So, we can find all the valid sum values with the help of subset sum problem solution before totalArrSum/2, bcoz for the sum of second subset we can directly subtract it from the totalArrSum */

#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> subsetSumProblem(vector<int> &arr, int n, int sum) {
  vector<vector<bool>> dp(n+1, vector<bool> (sum+1));

  // Initialization
  for(int i=0; i<=n; i++) dp[i][0] = 1;
  for(int i=1; i<=sum; i++) dp[0][i] = 0;

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=sum; j++) {
      if(arr[i-1] <= j) {
        dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
      } else {
        dp[i][j] = dp[i-1][j];
      }
    }
  }

  return dp;
}

int findMinimumDiff(vector<int> &arr, int n) {
  // Now we want to find all the valid sums (which can be obtained from all the different subset of the array) possible

  int sum = accumulate(arr.begin(), arr.end(), 0);
  vector<vector<bool>> dp = subsetSumProblem(arr, n, sum);

  // the last row of dp contains all the possible valid sum because the number of elements will be n for that row.
  // since we want to find the minimum difference, we can limit our iteration till sum/2 because after sum/2 the difference will again repeat
  
  int minDiff = sum;
  for(int i=0; i<=sum/2; i++) {
    if(dp[n][i])
      minDiff = min(minDiff, abs(sum - i) - i);
  }

  return minDiff;
}

int main() {
  int n;
  cin >> n;

  vector<int> arr(n);
  for(int &val : arr) cin >> val;

  int minDiff = findMinimumDiff(arr, n);

  cout << minDiff << endl;
}