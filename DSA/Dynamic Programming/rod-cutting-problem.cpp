/*
  Rod Cutting Problem
  Problem statement: Given a rod with length N and two arrays pieces and prices. For each piece[i] the corresponding profit price is in price[i].
  So, we have to find the maximum profit that can be obtained by cutting the rod into different pieces.

  The array represents the different actions that can be done on the rod 

  It is same as unbounded Knapsack Problem. Its just another name for the same problem.
*/
#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsackBottomUp(int pieces[], int prices[], int L, int n) {
	int DP[n+1][L+1];

  /* Initialization */
  for(int i=0; i<max(n+1, L+1); i++) {
    if(i < n+1) DP[i][0] = 0;
    if(i < L+1) DP[0][i] = 0;
  }

  // for(int i=0; i<n+1; i++) {
  //   for(int j=0; j<W+1; j++) 
  //     cout << DP[i][j] << " ";
  //   cout << endl;
  // }

  for(int n1 = 1; n1 < n+1; n1++) {
		for(int w1 = 1; w1 < L+1; w1++) {
			if(pieces[n1-1] <= w1)
				DP[n1][w1] = max(prices[n1-1] + DP[n1][w1 - pieces[n1-1]], DP[n1-1][w1]);
			else
				DP[n1][w1] = DP[n1-1][w1];
		}
	}

  return DP[n][L];
}

// int main() {
// 	int n;
//   cin >> n;
  
//   int pieces[n], prices[n], L;
//   for(int i=0; i<n; i++) cin >> pieces[i];
//   for(int i=0; i<n; i++) cin >> prices[i];
//   cin >> L;

// 	int maxprices = unboundedKnapsackBottomUp(pieces, prices, L, n);
// 	cout << maxprices << endl;
// }



/* Recursion + Memoization Approach */
int rodCuttingProblem(vector<int> &prices, vector<int> &length, int n, int L) {
  // if rod length become zero or no action left to be done on the rod
  if(L == 0 || n == 0) {
    return 0;
  }

  if(length[n-1] <= L) {
    int consider = prices[n-1] + rodCuttingProblem(prices, length, n, L - length[n-1]);
    int notConsider = rodCuttingProblem(prices, length, n-1, L);

    return max(consider, notConsider);
  } else {
    return rodCuttingProblem(prices, length, n-1, L);
  }
}

int main() {
	int n;
  cin >> n;
  
  vector<int> prices(n), length(n);
  int L;

  for(int &val : length) cin >> val;
  for(int &val : prices) cin >> val;

  cin >> L;

  int maxProfit = rodCuttingProblem(prices, length, n, L);
  cout << maxProfit << endl;
}