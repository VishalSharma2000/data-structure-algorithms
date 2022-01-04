/* Just replace OR operator from subset sum problem to + */
#include <bits/stdc++.h>
using namespace std;

int totalSubsetSum (int arr[], int n, int sum) {
  int dp[n+1][sum+1];

  // Initialization

  // irrespective of number of elements in the set, subset with sum 0 is always possible
  // for empty set, if the required sum is more than 0, then no subset is possible
  for(int i=0; i<n+1; i++) dp[i][0] = 1; 
  for(int i=1; i<sum+1; i++) dp[0][i] = 0;


  // normal knapsack code
  for(int i = 1; i<n+1; i++) {
    
    for(int j = 1; j<sum+1; j++) {
      
      if(arr[i-1] <= j)
        dp[i][j] = dp[i-1][j - arr[i-1]] + dp[i-1][j];
      
      else 
        dp[i][j] = dp[i-1][j];
    }

  }

    for(int i = 0; i<n+1; i++) {
    for(int j = 0; j<sum+1; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }


  return dp[n][sum];
}

int main() {
  int n;cin >>n;

  int arr[n], sum;
  for(int i=0; i<n; i++) cin >> arr[i];

  cin >> sum;

  cout << totalSubsetSum(arr, n, sum) << endl;
}