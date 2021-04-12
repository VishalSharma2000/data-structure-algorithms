#include <bits/stdc++.h>
using namespace std;

int knapsackBottomUp(int weights[], int profit[], int W, int n) {
	int DP[n+1][W+1];

	/* If the space in knapsack is 0 or the number of objects present is zero, then the maximum profit 
	   which can be obtained is zero */
	for(int i=0; i<n+1; i++) 
		DP[i][0] = 0;
	for(int i=0; i<W+1; i++) 
		DP[0][i] = 0;


	/*
		Think it like this...initially you don't have any object with you to add into knapsack neither you have any space in knapsack

		DP[n1-1][w1 - weights[n1]] => states that if we are going to add the object with index n1 into the existing object list, so we
		will have to decrease the knapsack remaining space by weights[i] and then with the remaining space we will check which one is giving 
		more profit.

		The inner loop is checking for all weights from 1 to W, in recursive call we decrease the given weight with the weight of object
		and then check for the other elements if they can be added or not...same way but here we are checking for all the weights from 
		1 to W iteratively in the inner loop...
	*/
	for(int n1 = 1; n1 < n+1; n1++) {
		for(int w1 = 1; w1 < W+1; w1++) {
			if(weights[n1-1] <= w1)
				DP[n1][w1] = max(profit[n1-1] + DP[n1-1][w1 - weights[n1-1]], DP[n1-1][w1]);
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

	int maxProfit = knapsackBottomUp(weights, profit, W, n);
	cout << maxProfit << endl;
}