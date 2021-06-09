#include <bits/stdc++.h>
using namespace std;

int totalSubsetSum (int arr[], int n, int sum) {
  int DP[n+1][sum+1];

  // Initialization
  for(int i=0; i<n+1; i++) DP[i][0] = 1; 
  // irrespective of number of elements in the set, subset with sum 0 is always possible
  for(int i=1; i<sum+1; i++) DP[0][i] = 0;
  // for empty set, if the required sum is more than 0, then no subset is possible

  // normal knapsack code
  for(int n1 = 1; n1<n+1; n1++) {
    for(int sum1 = 1; sum1<sum+1; sum1++) {
      if(arr[n1-1] <= sum1)
        DP[n1][sum1] = DP[n1-1][sum1 - arr[n1-1]] + DP[n1-1][sum1];
      else 
        DP[n1][sum1] = DP[n1-1][sum1];
    }
  }

  return DP[n][sum];
}

int main() {
  int n;cin >>n;

  int arr[n], sum;
  for(int i=0; i<n; i++) cin >> arr[i];

  cin >> sum;

  cout << totalSubsetSum(arr, n, sum) << endl;
}