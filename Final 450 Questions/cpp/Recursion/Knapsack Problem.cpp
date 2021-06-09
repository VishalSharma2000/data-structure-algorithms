/*
    Recursive knapsack solution
    hint is taken from the problem - find all subsets of the set or find power set of the
    given set....
    
    So, the idea is to include particular object once and then recursive call for others
    and then exclude it and recursively call for other objects...
    So, for each objec we will have 2 possible cases - so total complexity => O(2^n)
*/
#include <bits/stdc++.h>
using namespace std;

void knapsackUtil(vector<int> &weights, vector<int> &profit, int W, int totalWeight, int totalProfit, int *maxProfit, int i) {
    int size = weights.size();
    
    if(totalWeight <= W) {
        *maxProfit = max(*maxProfit, totalProfit);
        if(totalWeight == W) return;
        /* if the included object's weight is already W, then including more 
        object will not be able to fit in knapsack */
    } else if(totalWeight > W) return;
    
    for(; i<size; i++) {
        totalWeight += weights[i];
        totalProfit += profit[i];
        
        knapsackUtil(weights, profit, W, totalWeight, totalProfit, maxProfit, i+1);
        
        totalWeight -= weights[i];
        totalProfit -= profit[i];
    }
}

void knapsack(vector<int> &weights, vector<int> &profit, int W) {
    vector<int> taken;
    int totalWeight = 0, totalProfit = 0;
    int maxProfit = INT_MIN;
    
    knapsackUtil(weights, profit, W, totalWeight, totalProfit, &maxProfit, 0);
    
    cout << " Maximum Profit: " << maxProfit << endl;
}

int main() {
    vector<int> weights;
    vector<int> profit;
    int W;
    
    int n;
    cin >> n;
    int val;
    for(int i=0; i<n && cin >> val; i++) weights.push_back(val);
    for(int i=0; i<n && cin >> val; i++) profit.push_back(val);
    
    cin >> W;
    
    knapsack(weights, profit, W);
}
