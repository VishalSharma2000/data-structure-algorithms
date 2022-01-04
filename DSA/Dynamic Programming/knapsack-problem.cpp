#include <bits/stdc++.h>
using namespace std;

/* Recursive Approach Start */
int KPRecursive(int weights[], int profit[], int W, int n) {
  if(W == 0 || n == 0) return 0;
  /* If no space left in the bag or their are no more elements to put in knapsack so now in this case the profit will be zero */

  /* Here we are taking decision on the last element of the array. 
  So, If the weight of the current element on which decision is being taken is less then the remaining space left in the bag then we have choice to either consider the element or don't consider the element otherwise if the current element's weight is more than available space then we can't consider that element. */

  if(weights[n-1] <= W) {
    int profitIfConsidered = profit[n-1] + KPRecursive(weights, profit, W - weights[n-1], n-1);
    int profitIfNotConsidered = KPRecursive(weights, profit, W, n-1);

    return max(profitIfConsidered, profitIfNotConsidered);
  }

  // If the weight of the current element is more than the remaining space then we can't consider the element
  return KPRecursive(weights, profit, W, n-1);
}
/* Recursive Approach End */





/* Memoization Approach Start */
#define MAX 100

int DP[MAX][MAX];

int KPMemoization(int weights[], int profit[], int W, int n) {
    // base condition of recursive calls
    if(n == 0 || W == 0) {
        /* if there are no elements to keep in knapsack or if there are no remaining space in the bag then the profit will be zero */
        return 0;
    }
    
    /*
        here w and n resemble that => if the remaining weight of the knapsack is w and
        starting n elements are the object with given weights and profit then what will
        be maximum profit...If we have already founded that value then return it 
        otherwise compute it, store it and then return it.
    */
    if(DP[W][n] != -1) return DP[W][n];
    
    if(weights[n-1] <= W) {
        return DP[W][n] = max(
          profit[n-1] + KPMemoization(weights, profit, W-weights[n-1], n-1), 
          KPMemoization(weights, profit, W, n-1)
        );
    } 
    
    // if the weight of the object at index n-1 is more that knapsack weight
    return DP[W][n] = KPMemoization(weights, profit, W, n-1);
}
/* Memoization Approach End */




/* Top Down Approach Start */
int KPTopDown(int weights[], int profit[], int W, int n) {
	int DP[n+1][W+1];

	/* If the space in knapsack is 0 or the number of objects present is zero, then the maximum profit 
	   which can be obtained is zero */
	for(int i=0; i<n+1; i++) 
		DP[i][0] = 0;
	for(int i=0; i<W+1; i++) 
		DP[0][i] = 0;

  /* At each iteration i we are checking if the ith element can be taken into consideration for all weight from 0 to W. If yes then we we find the max profit between (if object considered) or (if not considered), otherwise the maximum profit for the sub problem will be same as in the case when the object is not considered */
	for(int i = 1; i < n+1; i++) {
		for(int j = 1; j < W+1; j++) {
			if(weights[i-1] <= j)
        // subproblem(i, j) = max(curr_obj_profit + subproblem(i-1)(j - weight), subproblem(i-1, j))
				DP[i][j] = max(profit[i-1] + DP[i-1][j - weights[i-1]], DP[i-1][j]);
			else
				DP[i][j] = DP[i-1][j];
		}
	}


	return DP[n][W];
}

/* Top Down Approach End */

int main() {
    int n;
    cin >> n;
    
    int weights[n], profit[n], W;
    for(int i=0; i<n; i++) cin >> weights[i];
    for(int i=0; i<n; i++) cin >> profit[i];
    cin >> W;

    cout << "Recursive Solution: " << KPRecursive(weights, profit, W, n) << endl;
    
    memset(DP, -1, sizeof(DP));
    cout << KPMemoization(weights, profit, W, n) << endl;
}