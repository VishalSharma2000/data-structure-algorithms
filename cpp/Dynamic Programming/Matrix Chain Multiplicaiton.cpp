/*
  Given an array containing the size of the matrices, we have to find the minimum cost to multiply 
  all the matrices i.e. basically we have to add brackets between matrices and hence 
  find which matrices should we multiple first and which all after that...means the order in which the matrices should be multiplied
*/

#include <bits/stdc++.h>
using namespace std;

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

int main() {
  int n;
  cin >> n;

  int arr[n];
  for(int i=0; i<n; i++) cin >> arr[i];

  cout << MCM(arr, n) << endl;
}