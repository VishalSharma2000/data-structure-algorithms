/*
  Given an array containing the size of the matrices, we have to find the minimum cost to multiply 
  all the matrices i.e. basically we have to add brackets between matrices and hence 
  find which matrices should we multiple first and which all after that...means the order in which the matrices should be multiplied


*/

#include <bits/stdc++.h>
using namespace std;

#define SIZE 1001
int dp[SIZE][SIZE];

int MCMUtil(int arr[], int i, int j) {
  if(i >= j) return 0;

  int minCost = INT_MAX;
  for(int k=i; k<=j-1; k++) {
    int tempSol = MCMUtil(arr, i, k) + MCMUtil(arr, k+1, j) + (arr[i-1] * arr[k] * arr[j]);
  
    minCost = min(minCost, tempSol);
  }

  return minCost;
}

int MCM(int arr[], int n) {
  return MCMUtil(arr, 1, n-1);
}

int MCMUtilMemoized(int arr[], int i, int j) {
  if(i >= j) return 0;
  /* There should be atleast one matrix in both the set to calculate the cost properly...
  hence if i == j then the size of the array becomes 1 which will not indicate any matrix...
  to get the dimension of atleast one matrix the size of the array should be 2 */

  /* As always, in memoized version we first check that - if we have already solve the subproblem
  if yes then return the answer otherwise calculate it and store for future use */
  if(dp[i][j] != -1) return dp[i][j];

  int minCost = INT_MAX;
  for(int k=i; k<=j-1; k++) {
    int tempSol = (
      MCMUtilMemoized(arr, i, k) +        // solve for the left part of the chain matrix
      MCMUtilMemoized(arr, k+1, j) +      // solve for the right part of the chain matrix
      (arr[i-1] * arr[k] * arr[j])        // after multiplication of the left part and right, multiply the obtained resultant matrix
    );

    minCost = min(minCost, tempSol);
  }

  return dp[i][j] = minCost;
}

int MCMMemoized(int arr[], int n) {
  memset(dp, -1, sizeof(dp));

  return  MCMUtilMemoized(arr, 1, n-1);
}

int main() {
  int n;
  cin >> n;

  int arr[n];
  for(int i=0; i<n; i++) cin >> arr[i];

  cout << MCM(arr, n) << endl;

  // memoized version
  cout << MCMMemoized(arr, n) << endl;
}