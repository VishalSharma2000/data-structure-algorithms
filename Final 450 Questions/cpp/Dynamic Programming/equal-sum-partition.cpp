#include <bits/stdc++.h>
using namespace std;

/* 
  Problem Stmt: We have to divide the array into two partition such that the sum of both the partition is same.
 */

/* 
  Main Idea. 
  Very first intuition here is, if we want the sum of two subset to be same then the sum of whole array should be divisible by 2 
  otherwise it cannot be divided into two parts.

  Secondly, to check if partition can be done or not we just have to find that the subset with sum = totalArrSum /2 exist or not 
  bcoz if this sub array exist then its obvoius that the sum of the other subset will be automatically totalArrSum / 2;  
*/

bool subsetSumPbm(vector<int> &arr, int n, int sum) {
  /* Bottom Up Approach */
  bool dp[n+1][sum+1];

  /* Initialization */
  for(int i=0; i<n+1; i++) dp[i][0] = 1; /* Empty set can be created for sum = 0 */
  for(int i=1; i<sum+1; i++) dp[0][i] = 0; /* No subset can be created if no elements are present in the original set */

  for(int i=1; i<n+1; i++) {
    for(int j=1; j<sum+1; j++) {
      if(arr[i-1] <= j)
        dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
      else 
        dp[i][j] = dp[i-1][j];
    }
  }

  return dp[n][sum];
}

bool equalSumPartition(vector<int> &arr, int n) {
  int sum = accumulate(arr.begin(), arr.end(), 0);

  if(sum%2 != 0) return false;
  /* If the sum of subarray cannot be divisble by 2 then the array cannot be divided into two parts. Hence return false */

  return subsetSumPbm(arr, n, sum/2);
}

int main() {
  int n; cin >>n;

  vector<int> arr(n);
  for(int i=0; i<n; i++) {
    int val; cin >> val;
    arr[i] = val;
  }

  cout << equalSumPartition(arr, n) << endl;
}