#include <bits/stdc++.h>
using namespace std;


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