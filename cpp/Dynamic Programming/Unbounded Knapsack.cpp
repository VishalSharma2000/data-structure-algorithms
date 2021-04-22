#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsackBottomUp(int weights[], int profit[], int W, int n) {
	int DP[n+1][W+1];

  /* Initialization */
  for(int i=0; i<max(n+1, W+1); i++) {
    if(i < n+1) DP[i][0] = 0;
    if(i < W+1) DP[0][i] = 0;
  }

  // for(int i=0; i<n+1; i++) {
  //   for(int j=0; j<W+1; j++) 
  //     cout << DP[i][j] << " ";
  //   cout << endl;
  // }

  for(int n1 = 1; n1 < n+1; n1++) {
		for(int w1 = 1; w1 < W+1; w1++) {
			if(weights[n1-1] <= w1)
				DP[n1][w1] = max(profit[n1-1] + DP[n1][w1 - weights[n1-1]], DP[n1-1][w1]);
			else
				DP[n1][w1] = DP[n1-1][w1];
		}
	}

  return DP[n][W];
}

int main() {
	int n;
    cin >> n;
    
    int weights[n], profit[n], W;
    for(int i=0; i<n; i++) cin >> weights[i];
    for(int i=0; i<n; i++) cin >> profit[i];
    cin >> W;

	int maxProfit = unboundedKnapsackBottomUp(weights, profit, W, n);
	cout << maxProfit << endl;
}