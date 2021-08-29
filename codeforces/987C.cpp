#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long	

void solve() {
	int n;
	cin >> n;

	vector<int> fs(n), cost(n);
	for(int &val : fs) cin >> val;
	for(int &val : cost) cin >> val;

  /* Brute Force Approach, TC: O(N^3) */ 
  int minCost = INT_MAX;
	for(int i=0; i<n-2; i++) {
		for(int j=i+1; j<n-1; j++) {
			if(fs[j] > fs[i]) {
				for(int k=j+1; k<n; k++) {
					if(fs[k] > fs[j]) {
						minCost = min(minCost, cost[i] + cost[j] + cost[k]);
					}
				}
			}
		}
	}


	cout << minCost << endl;


  /* Efficient O(N^2) Approach, The idea is to fix the index j and then kind of use two pointer in two opposite direction to find the nos which satisfy the given condition. 
  So, for all j, iterate i from j-1 to 0 and iterate k from j+1 to n-1 
  for i find the display with minimum cost and less font size 
  and for k find the display with minimum cost and more font size */
  /* Here we can't think of precomputing mincost till index i or max cost till index j bcoz of the factors.
  First we don't want just max or min cost we want the max and min cost in respect to font size what is present at position j */
	int finalMinCost = INT_MAX;
  
  for(int j=1; j<n-1; j++) {
		int i = j-1; 
		int minCost = INT_MAX;
		while(i >= 0) {
			if(fs[i] < fs[j])
				minCost = min(minCost, cost[i]);
			i--;
		}

		if(minCost == INT_MAX) continue;

		int minCost2 = INT_MAX;
		int k = j+1;
		while(k < n) {
			if(fs[k] > fs[j])
				minCost2 = min(minCost2, cost[k]);
			k--;
		}

		if(minCost2 == INT_MAX) continue;
		finalMinCost = min(finalMinCost, minCost + minCost2 + cost[j]);
	}	

	cout << finalMinCost << endl;
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	// ll t;
	// cin >> t;

	// while(t--) {
		solve();
	// }	

	return 0;
}
