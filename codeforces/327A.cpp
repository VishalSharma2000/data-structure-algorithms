#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long


// brute force approach to solve the question
void printSubarray() {
	int n;
	cin >> n;

	vector<int> arr;
	for(int i=0; i<n; i++) {
		int val; cin >> val;
		arr.push_back(val);
	}
	int maxOnes = 0;

	// i => starting point
	// j => ending point
	// k => to print the subarray from start to end

	for(int i=0; i<n; i++) {
		for(int j=i; j<n; j++) {
			int o1 = 0, o2 = 0;
			for(int k=0; k<n; k++) {
				if(k >= i && k <= j) {
					if(arr[k] == 1) o2++;					
				} else if(arr[k] == 1) o1++;
			}
			int size = abs(j-i+1);
			maxOnes = max(maxOnes, o1 + (size - o2));
		}
	}
	cout << maxOnes << endl;
}

// O(n) approach
void solve() {
	int n;
	cin >> n;

	vector<int> arr;
	for(int i=0; i<n; i++) {
		int val; cin >> val;
		arr.push_back(val);
	}

	int start = -1, end = 0;
	int cnt = 0, maxCnt = INT_MIN;
	int maxCntS, maxCntE;
	// find the subarray with maximum difference in zero and onces count.
	while(end < n) {
		arr[end] == 0 ? cnt++ : cnt--;

		if(cnt > maxCnt) {
			maxCnt = cnt;
			maxCntS = start;
			maxCntE = end;
		}

		if(cnt < 0) {
			start = end;
			end = end+1;
			cnt = 0;
		} else {
			end++;
		}
	}

	// find the number of ones outside the subarray which we found in the above loop
	int o1 = 0;
	for(int i=0; i<n; i++) {
		if(!(i >= maxCntS+1 && i <= maxCntE)) {
			if(arr[i] == 1) o1++;
		}
	}

	// total onces = outside onces + difference in ones and zeros + ones
	cout << o1 + maxCnt + ((maxCntE-maxCntS) - maxCnt)/2 << endl;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	// ll t;
	// cin >> t;

	// while(t--) {
		solve();
	// }	

	// printSubarray();

	return 0;
}
