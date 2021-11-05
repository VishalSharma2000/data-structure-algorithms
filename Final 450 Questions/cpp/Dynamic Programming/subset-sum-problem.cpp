#include <bits/stdc++.h>
using namespace std;

/* Recursive Appproach Start */
bool subsetSum(vector<int> &arr, int n, int sum) {
  if(sum == 0) {
    return true;
  }

  if(n == 0) { 
    return false;
  }

  if(arr[n-1] <= sum) {
    bool consider = subsetSum(arr, n-1, sum - arr[n-1]);
    bool notConsider = subsetSum(arr, n-1, sum);

    return consider || notConsider;
    /*
      return subsetSum(arr, n-1, sum-arr[n-1]) || subsetSum(arr, n-1, sum);
    */
  } else {
    return subsetSum(arr, n-1, sum);
  }
}
/* Recursive Appproach End */


/* Memoization Approach Start */
bool subsetSum(vector<int> &arr, int n, int sum) {
  if(sum == 0) {
    return true;
  }

  if(n == 0) {
    return false;
  }

  if(memo[n][sum] != -1) return memo[n][sum];

  if(arr[n-1] <= sum) {
    memo[n][sum] = subsetSum(arr, n-1, sum - arr[n-1]) || subsetSum(arr, n-1, sum);
  } else {
    memo[n][sum] = subsetSum(arr, n-1, sum);
  }

  return memo[n][sum];
}

/* Memoization Approach End */


/* Bottom Up Approach Start */
bool subsetSumPossible(int arr[], int n, int sum) {
  bool DP[n+1][sum+1];

  /*
    Row => size of the array
    Column => required Sum

    Initialization:
      1st Column will be all true: bcoz to get a sum of zero we can have an empty set...so if are not provided with any value
      in the array then also we can have a subset(empty set) with sum equal zero.
      1st Row (i = 1 to sum) will be false: bcoz if we are not provided with any number in the array then we can't have any 
      sum more than 0
  */

    for(int i=0; i<n+1; i++) DP[i][0] = 1;
    for(int i=1; i<sum+1; i++) DP[0][i] = 0;

    for(int i=1; i<n+1; i++) {
      for(int j=1; j<sum+1; j++) {
        if(arr[i-1] <= j) {
          /* If the element value at array index i-1 is less than j then we have two options. We can either included it into
          our subset or don't include. 
          If we are gonna include then the new sum required will be lastSum - currValue
          This is a subproblem   */
          DP[i][j] = DP[i-1][sum - j] || DP[i-1][j];
        } else {
          DP[i][j] = DP[i-1][j];
        }
      }
    }

    return DP[n][sum];
}

/* Bottom Up Approach End */


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
  cout << subsetSumPbmRecursive(arr, n, sum, 0) << endl;
}