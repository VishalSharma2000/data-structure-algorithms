/*
  Time Complexity: O(n * sum)
  Space Complexity : O(sum)
*/
#include <bits/stdc++.h>
using namespace std;

bool subsetSumPossible(int arr[], int n, int sum) {
  bool dp[sum+1];

  /*
    Standard Subset Sub problem has the following relation
    dp[i][j] = numd[i-1] >= j ? dp[i-1][j-nums[i-1]] || dp[i-1][j] : dp[i-1][j];

    It can be noticed that, each time only the previous row will be accessed. Not the rows before that..
    suppose i = 3, sum = x then for filling all the values of row i only the (i-1)th row will be needed. 
    By this observation, we can do it 1d array also.
  */

  dp[0] = 1; // initialization

  /*
    Using an extra variable to track the sum till ith number.
    In inner for loop is initialization with min(tempSum, sum) so that we can get the maximum sum which
    can be obtained by considering arr[i]

    and the termination condition is the minimum sum that can be obtained with arr[i]
  */
  int tempSum = 0;
  for(int i=0; i<n; i++) {

    tempSum += arr[i];
    for(int sum1=min(tempSum, sum); sum1>=arr[i]; sum1--) {
      if(arr[i] >= sum1) dp[i] = dp[i-arr[i]];
    }
  }

  return dp[sum];
}
int main() {
  int n;cin >>n;

  int arr[n], sum;
  for(int i=0; i<n; i++) cin >> arr[i];

  cin >> sum;

  cout << subsetSumPossible(arr, n, sum) << endl;
}