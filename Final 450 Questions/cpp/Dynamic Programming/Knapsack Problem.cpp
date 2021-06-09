#include <bits/stdc++.h>
using namespace std;

#define MAX 100

int DP[MAX][MAX];

int knapsackDP(int weights[], int profit[], int W, int n) {
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
        return DP[W][n] = max(profit[n-1] + knapsackDP(weights, profit, W-weights[n-1], n-1), knapsackDP(weights, profit, W, n-1));
    } 
    
    // if the weight of the object at index n-1 is more that knapsack weight
    return DP[W][n] = knapsackDP(weights, profit, W, n-1);
}

int main() {
    int n;
    cin >> n;
    
    int weights[n], profit[n], W;
    for(int i=0; i<n; i++) cin >> weights[i];
    for(int i=0; i<n; i++) cin >> profit[i];
    cin >> W;
    
    memset(DP, -1, sizeof(DP));
    cout << knapsackDP(weights, profit, W, n) << endl;
}